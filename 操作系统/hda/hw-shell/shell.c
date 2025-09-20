#include <ctype.h>
#include <errno.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/wait.h>
#include <termios.h>
#include <unistd.h>

#include "tokenizer.h"

/* Convenience macro to silence compiler warnings about unused function parameters. */
#define unused __attribute__((unused))

/* Whether the shell is connected to an actual terminal or not. */
bool shell_is_interactive;

/* File descriptor for the shell input */
int shell_terminal;

/* Terminal mode settings for the shell */
struct termios shell_tmodes;

/* Process group id for the shell */
pid_t shell_pgid;

int cmd_exit(struct tokens *tokens);
int cmd_help(struct tokens *tokens);
int cmd_pwd(struct tokens *tokens);
int cmd_cd(struct tokens *tokens);
int cmd_run_prog(struct tokens *tokens);

/* Built-in command functions take token array (see parse.h) and return int */
typedef int cmd_fun_t(struct tokens *tokens);

/* Built-in command struct and lookup table */
typedef struct fun_desc
{
  cmd_fun_t *fun;
  char *cmd;
  char *doc;
} fun_desc_t;

fun_desc_t cmd_table[] = {
    {cmd_help, "?", "show this help menu"},
    {cmd_exit, "exit", "exit the command shell"},
    {cmd_pwd, "pwd", "current working directory"},
    {cmd_cd, "cd", "change current working directory"},
    {cmd_run_prog, "run_prog", "execute programs"}};

/* Prints a helpful description for the given command */
int cmd_help(unused struct tokens *tokens)
{
  for (unsigned int i = 0; i < sizeof(cmd_table) / sizeof(fun_desc_t); i++)
    printf("%s - %s\n", cmd_table[i].cmd, cmd_table[i].doc);
  return 1;
}

/* Exits this shell */
int cmd_exit(unused struct tokens *tokens) { exit(0); }

int cmd_pwd(unused struct tokens *tokens)
{
  char pwd[4096];
  if (getcwd(pwd, sizeof(pwd)) != NULL)
  {
    printf("%s\n", pwd);
  }
  else
  {
    perror("Error getting current working directory!");
  }
  return 0;
}
/* Change the current working directory to the specified path */
int cmd_cd(struct tokens *tokens)
{
  if (tokens_get_length(tokens) != 2)
  {
    printf("cd: destination path required!\n");
    return 1;
  }

  char *path = tokens_get_token(tokens, 1);
  if (chdir(path) != 0)
  {
    perror("Error changing directory!");
    return 1;
  }
  return 0;
}

// Return the full path, we need to ensure the returned path exists
char *get_full_path(const char *input_path)
{
  if (input_path == NULL)
  {
    return NULL;
  }
  // Check if the path exists (starts with /)
  if (input_path[0] == '/')
  {
    if (access(input_path, F_OK) != -1)
    {
      // Return the path
      return strdup(input_path);
    }
    else
    {
      return NULL;
    }
  }
  // Search for the first possible path based on environment variables
  else
  {
    char *env_path = getenv("PATH");
    if (env_path == NULL)
    {
      // Environment variable does not exist
      return NULL;
    }
    // Copy the environment variable
    char *env_path_copy = strdup(env_path);
    if (env_path_copy == NULL)
    {
      // Memory allocation failed
      perror("Memory allocation failed");
      exit(EXIT_FAILURE);
    }
    // Split the environment variable by :
    char *path = strtok(env_path_copy, ":");
    // Match based on the environment variable path
    while (path != NULL)
    {
      // Allocate space for the full path
      size_t path_length = strlen(path) + strlen(input_path) + 2;
      char *full_path = (char *)malloc(path_length);
      if (full_path == NULL)
      {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
      }
      // Concatenate to get the full path
      snprintf(full_path, path_length, "%s/%s", path, input_path);
      // If the first existing path is found
      if (access(full_path, F_OK) != -1)
      {
        free(env_path_copy);
        char *result = strdup(full_path);
        if (result == NULL)
        {
          perror("Memory allocation failed");
          exit(EXIT_FAILURE);
        }
        free(full_path);
        return result;
      }
      // Need to free the full path
      free(full_path);
      // Get the next environment variable
      path = strtok(NULL, ":");
    }
    // If no path is found under all environment variables
    free(env_path_copy);
    return NULL;
  }
}
int redirect_output(char *file_path)
{
  if (file_path == NULL)
  {
    perror("Missing file path parameter!");
    return 1;
  }
  // Open the file, create it if it doesn't exist
  FILE *file = fopen(file_path, "w");
  if (file == NULL)
  {
    perror("Error opening file!");
    return 1;
  }
  if (freopen(file_path, "w", stdout) == NULL)
  {
    perror("Failed to redirect standard output to file!");
    fclose(file);
    return 1;
  }
  return 0;
}

 int redirect_input(char *file_path)
{
  if (file_path == NULL)
  {
    perror("Missing file path parameter!");
    return 1;
  }
  // Open the file, should report an error if it doesn't exist
  FILE *file = fopen(file_path, "r");
  if (file == NULL)
  {
    perror("Error opening file!");
    return 1;
  }
  if (freopen(file_path, "r", stdin) == NULL)
  {
    perror("Failed to redirect standard input to file!");
    fclose(file);
    return 1;
  }
  return 0;
}

int reset_stdio()
{
  freopen("/dev/tty", "w", stdout);
  freopen("/dev/tty", "r", stdin);
  return 0;
}
/* Run external program */
int cmd_run_prog(struct tokens *tokens)
{
  int tokens_length = tokens->tokens_length;
  // Check if at least one argument is provided
  if (tokens_length < 1)
  {
    printf("run: At least one command or executable path is required\n");
    return 1;
  }

  // Get the full path of the program
  char *program_path = get_full_path(tokens->tokens[0]);
  if (program_path == NULL)
  {
    printf("File not found!\n");
    return 1;
  }
  // Whether to redirect input/output to file (1 for yes, 0 for no)
  int is_redirected = 0;
  if (tokens_length >= 3)
  {
    // Need to redirect output to file
    if (strcmp(tokens->tokens[tokens_length - 2], ">") == 0)
    {
      is_redirected = 1;
      if (redirect_output(tokens->tokens[tokens_length - 1]) != 0)
      {
        return 1;
      }
    }
    // Need to redirect input from file
    else if (strcmp(tokens->tokens[tokens_length - 2], "<") == 0)
    {
      is_redirected = 1;
      if (redirect_input(tokens->tokens[tokens_length - 1]) != 0)
      {
        return 1;
      }
    }
  }
  // Create child process
  pid_t pid = fork();
  if (pid == -1)
  {
    perror("Failed to create child process!");
    return 1;
  }
  else if (pid == 0)
  {
    // Set the process group of the child process, both parameters are 0 to set pgid to the same value as its pid
    setpgid(0, 0);
    // Put the child process in the foreground, the second parameter is pgid, which is equal to pid
    // Set the child process to default behavior for Ctrl-C and Ctrl-Z signals.
    signal(SIGINT, SIG_DFL);
    signal(SIGTSTP, SIG_DFL);
    signal(SIGTTOU, SIG_DFL);
    int new_argc = tokens->tokens_length;
    if (is_redirected == 1) // If input/output redirection is used, do not pass the last two arguments
      new_argc = new_argc - 2;
    char **argv = malloc((new_argc + 1) * sizeof(char *));
    if (argv == NULL)
    {
      perror("Memory allocation failed!\n");
      return 1;
    }
    // Copy strings from tokens
    for (size_t i = 0; i < new_argc; ++i)
    {
      argv[i] = tokens->tokens[i];
    }
    // Place NULL terminator at the end of the array
    argv[new_argc] = NULL;
    // Execute the program in the child process.
    execv(program_path, argv);
    perror("Error executing child process!");
    exit(EXIT_FAILURE);
  }
  // fork returns a positive number, indicating the current process is the parent process, and pid is the id of the child process
  else
  {
    signal(SIGINT, SIG_IGN);
    // Put the child process in the foreground
    tcsetpgrp(shell_terminal, pid);
    int status;
    waitpid(pid, &status, 0);
    tcsetpgrp(shell_terminal, shell_pgid);
    signal(SIGINT, SIG_DFL);
    // Redirect input and output back to the terminal
    reset_stdio();
  }
  reset_stdio();
  return 0;
}

/* Looks up the built-in command, if it exists. */
int lookup(char cmd[])
{
  for (unsigned int i = 0; i < sizeof(cmd_table) / sizeof(fun_desc_t); i++)
    if (cmd && (strcmp(cmd_table[i].cmd, cmd) == 0))
      return i;
  return -1;
}

/* Intialization procedures for this shell */
void init_shell()
{
  /* Our shell is connected to standard input. */
  shell_terminal = STDIN_FILENO;

  /* Check if we are running interactively */
  shell_is_interactive = isatty(shell_terminal);

  signal(SIGINT, SIG_DFL);
  signal(SIGTSTP, SIG_IGN);
  signal(SIGTTOU, SIG_IGN);

  if (shell_is_interactive)
  {
    /* If the shell is not currently in the foreground, we must pause the shell until it becomes a
     * foreground process. We use SIGTTIN to pause the shell. When the shell gets moved to the
     * foreground, we'll receive a SIGCONT. */
    while (tcgetpgrp(shell_terminal) != (shell_pgid = getpgrp()))
      kill(-shell_pgid, SIGTTIN);

    /* Saves the shell's process id */
    shell_pgid = getpid();

    /* Take control of the terminal */
    tcsetpgrp(shell_terminal, shell_pgid);

    /* Save the current termios to a variable, so it can be restored later. */
    tcgetattr(shell_terminal, &shell_tmodes);
  }
}

int main(unused int argc, unused char *argv[])
{
  init_shell();

  static char line[4096];
  int line_num = 0;

  /* Please only print shell prompts when standard input is not a tty */
  if (shell_is_interactive)
    fprintf(stdout, "%d: ", line_num);

  while (fgets(line, 4096, stdin))
  {
    /* Split our line into words. */
    struct tokens *tokens = tokenize(line);

    /* Find which built-in function to run. */
    int fundex = lookup(tokens_get_token(tokens, 0));

    if (fundex >= 0)
    {
      cmd_table[fundex].fun(tokens);
    }
    else
    {
      /* REPLACE this to run commands as programs. */
      cmd_run_prog(tokens);
    }

    if (shell_is_interactive)
      /* Please only print shell prompts when standard input is not a tty */
      fprintf(stdout, "%d: ", ++line_num);

    /* Clean up memory */
    tokens_destroy(tokens);
  }

  return 0;
}
