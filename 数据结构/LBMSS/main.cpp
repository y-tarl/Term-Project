#include "Menu/Menu.h"
#include "Object/Book.h"
#include "System/UserSystem.h"
#include "System/LibrarySystem.h"

using namespace std;

int main() {
    LibrarySystem librarySystem;
    librarySystem.initialization("../data/Library.txt");
    UserSystem userSystem;
    userSystem.Initialization("../data/User.txt");
    Menu::Init();
    int choice;
    while (cin >> choice && choice) {
        switch (choice) {
            case 1: {
                Node<User> *user = userSystem.Login();
                if (!user) {
                    break;
                }
                if (user->data.getUserType() == UserType::ADMIN) {
                    Menu::AdminMain();
                    while (cin >> choice && choice) {
                        switch (choice) {
                            case 1: {
                                librarySystem.add();
                                break;
                            }
                            case 2: {
                                Menu::Search();
                                while (cin >> choice && choice) {
                                    switch (choice) {
                                        case 1: {
                                            librarySystem.findByID();
                                            break;
                                        }
                                        case 2: {
                                            librarySystem.findByISBN();
                                            break;
                                        }
                                        case 3: {
                                            librarySystem.findByTitle();
                                            break;
                                        }
                                        case 4: {
                                            librarySystem.display();
                                            break;
                                        }
                                        default: {
                                            cout << "输入有误, 请重新输入" << endl;
                                            break;
                                        }
                                    }
                                    Menu::Search();
                                }
                                break;
                            }
                            case 3: {
                                Menu::Update();
                                while (cin >> choice && choice) {
                                    switch (choice) {
                                        case 1:
                                        case 2:
                                        case 3: {
                                            librarySystem.Change(choice);
                                            break;
                                        }
                                        default: {
                                            cout << "输入有误, 请重新输入" << endl;
                                            break;
                                        }
                                    }
                                    Menu::Update();
                                }
                                break;
                            }
                            case 4: {
                                Menu::Remove();
                                while (cin >> choice && choice) {
                                    switch (choice) {
                                        case 1:
                                        case 2:
                                        case 3: {
                                            librarySystem.Remove(choice);
                                            break;
                                        }
                                        default: {
                                            cout << "输入有误, 请重新输入" << endl;
                                            break;
                                        }
                                    }
                                    Menu::Remove();
                                }
                                break;
                            }
                            case 5: {
                                userSystem.changePassword(user);
                                break;
                            }
                            case 6: {
                                userSystem.display();
                                break;
                            }
                            default: {
                                cout << "输入有误, 请重新输入" << endl;
                                break;
                            }
                        }
                        Menu::AdminMain();
                    }
                } else {
                    Menu::GenerMain();
                    while (cin >> choice && choice) {
                        switch (choice) {
                            case 1: {
                                Menu::Search();
                                while (cin >> choice && choice) {
                                    switch (choice) {
                                        case 1: {
                                            librarySystem.findByID();
                                            break;
                                        }
                                        case 2: {
                                            librarySystem.findByISBN();
                                            break;
                                        }
                                        case 3: {
                                            librarySystem.findByTitle();
                                            break;
                                        }
                                        case 4: {
                                            librarySystem.display();
                                            break;
                                        }
                                        default: {
                                            cout << "输入有误, 请重新输入" << endl;
                                            break;
                                        }
                                    }
                                    Menu::Search();
                                }
                                break;
                            }
                            case 2: {
                                user->data.disBook();
                                break;
                            }
                            case 3: {
                                Menu::LendOrReturn();
                                while (cin >> choice && choice) {
                                    switch (choice) {
                                        case 1: {
                                            librarySystem.Lend(user);
                                            userSystem.Save();
                                            break;
                                        }
                                        case 2: {
                                            librarySystem.Return(user);
                                            userSystem.Save();
                                            break;
                                        }
                                        default: {
                                            cout << "输入有误, 请重新输入" << endl;
                                            break;
                                        }
                                    }
                                    Menu::LendOrReturn();
                                }
                                break;
                            }
                            case 4: {
                                userSystem.changePassword(user);
                                break;
                            }
                            default: {
                                cout << "输入有误, 请重新输入" << endl;
                                break;
                            }
                        }
                        Menu::GenerMain();
                    }
                }
                break;
            }
            case 2: {
                userSystem.Register();
                break;
            }
            default: {
                cout << "输入有误, 请重新输入" << endl;
                break;
            }
        }
        Menu::Init();
    }
    userSystem.Save();
    librarySystem.save();
    cout << "欢迎下次使用" << endl;
    return 0;
}
