#ifndef USERPROG_SYSCALL_H
#define USERPROG_SYSCALL_H

#include <stdbool.h>
#include <stdio.h>

void syscall_init(void);

// 添加我们创建的两个用于验证指针的函数
bool is_valid_int(uint32_t* ptr);
bool is_valid_ptr(char* ptr);

#endif /* userprog/syscall.h */
