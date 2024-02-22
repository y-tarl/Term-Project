//
// Created by Tarl on 2023-12-30.
//

#ifndef LBMSS_MENU_H
#define LBMSS_MENU_H

#include <iostream>
#include <string>
#include <vector>

class Menu {
public:
    // 初始菜单
    static void Init();

    // 管理员菜单
    static void AdminMain();
    // 读者菜单
    static void GenerMain();

    // 查找菜单
    static void Search();

    // 更新菜单
    static void Update();

    // 删除菜单
    static void Remove();

    // 借出或归还菜单
    static void LendOrReturn();

    static  void pointer();//->
    static   void reenter();//重新输入
};







#endif //LBMSS_MENU_H
