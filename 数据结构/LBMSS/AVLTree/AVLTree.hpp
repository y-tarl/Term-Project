//
// Created by Tarl on 2023-12-30.
//

#ifndef LBMSS_LIBRARY_BOOK_MANAGEMENT_SYSTEM_SIMULATION__AVLTREE_H
#define LBMSS_LIBRARY_BOOK_MANAGEMENT_SYSTEM_SIMULATION__AVLTREE_H

#include <iostream>
#include <algorithm>
#include <fstream>
#include "Node.hpp"

using namespace std;

template<typename T>
class AVLTree {
private:
    Node<T> *root;

    Node<T> *insert(Node<T> *&node, Node<T> *parent, const T &data);//插入辅助函数
    //这里如果不用指针的引用，那么当空结点作为形参进行传递时，就无法将new出的新的结点传给原指针
//    bool remove(Object<T>* node, const T&  data);//删除辅助函数
    Node<T> *find(Node<T> *node, const T &data);//查找辅助函数

    void show(Node<T> *node) const;//中序遍历输出辅助函数
    void show(Node<T> *node, ostream &ou) const;//重载中序遍历输出辅助函数
    int num;//存储结点的数量
public:
    AVLTree() : root(nullptr), num(0) {}

    int getNum() const;//返回结点个数
    Node<T> *begin();//返回中序遍历的第一个结点
    Node<T> *insert(const T &data);//插入结点
    void Balancing(Node<T> *node);//调整因插入node结点所改变的平衡因子
    bool add(const T &data);//添加图书，包括插入和平衡操作
    bool remove(Node<T> *node);//删除
    Node<T> *find(const T &data);//查找
    void clear(Node<T> *node);//清空
    void show() const;//中序遍历输出查看
    void show(ostream &ou) const;//重载中序遍历输出查看
    bool empty() const;//判空
    void R(Node<T> *center);//以center为中心右旋
    void L(Node<T> *center);//以center为中心左旋

    const Node<T> *Root() const;//返回一个根节点，但不可更改，只是便于查看根节点存储的数据

    //友元类
    friend class LibrarySystem;

    friend class UserSystem;

    friend class User;
};


template<typename T>
bool AVLTree<T>::empty() const {
    return root == nullptr;
}

template<typename T>
int AVLTree<T>::getNum() const {
    return num;
}

template<typename T>
Node<T> *AVLTree<T>::insert(const T &data) {
    return insert(root, nullptr, data);
}

template<typename T>
Node<T> *AVLTree<T>::insert(Node<T> *&node, Node<T> *parent, const T &data) {
    if (node == nullptr) {
        node = new Node<T>(data, parent);
        ++num;
        return node;
    } else if (data < node->data) {
        return insert(node->left, node, data);
    } else if (data > node->data) {
        return insert(node->right, node, data);
    } else {
        cout << "数据：\n" << data << "重复！添加失败！\n";
        return nullptr;  // 数据重复，不插入
    }
}


template<typename T>
bool AVLTree<T>::remove(Node<T> *node) {
    if (node == nullptr) return false;
    if (node->hasChild() == 2) {//待删结点有两个孩子，进行替换
        Node<T> *p = node->next();
        swap(p->data, node->data);
        node = p;
    }
    Node<T> *child = node->left;
    if (child == nullptr) child = node->right;
    if (node->parent) {//待删结点不为根节点
        Node<T> *p = node, *brother;
        //在删除之前调整平衡因子
        if (node->parent->balance) {//如果待删结点的父节点原先的平衡因子为0,那么删除结点并不会影响其父节点以上的结点
            while (p->parent && abs(p->balance) < 2) {
                if (p->isLR() == 1) brother = p->parent->right;
                else brother = p->parent->left;
                p->parent->balance -= p->isLR();
                p = p->parent;
            }

        } else node->parent->balance -= node->isLR();

        if (node->isLR() == 1) node->parent->left = child;//父节点接管子节点
        else node->parent->right = child;

        if (abs(p->balance) > 1) {//平衡因子不平衡，需要进行旋转
            if (p->balance * brother->balance < 0) {//异号，需要进行两次旋转
                Node<T> *c;
                if (brother->balance > 0) {
                    c = brother->left;
                    R(c);
                } else {
                    c = brother->right;
                    L(c);
                }
                swap(c, brother);//此时LRC与C的结点位置已经互换
            }
            if (p->balance > 0) {//再进行一轮旋转
                R(brother);
            } else L(brother);
        }

    } else {
        root = child;
    }
    delete node;
    num--;
    return true;
}

//template <typename T>
//bool  AVLTree<T>::remove(Object<T>* node,const T&  data) {
//    // 删除逻辑...
//    // 平衡逻辑...
//    return node;
//}
template<typename T>
Node<T> *AVLTree<T>::find(Node<T> *node, const T &data) {
    if (node) {
        if (data == node->data) return node;
        if (data < node->data) return find(node->left, data);
        else return find(node->right, data);
    }
    return nullptr;
}

template<typename T>
Node<T> *AVLTree<T>::find(const T &data) {
    return find(root, data);
}

template<typename T>
void AVLTree<T>::clear(Node<T> *node) {
    if (node == nullptr) {
        return;
    }
    Node<T> *l = node->left;
    Node<T> *r = node->right;
    delete node;
    if (l) {
        clear(l);
    }
    if (r) {
        clear(r);
    }
}


//template <typename T>
//AVLTree<T>::~AVLTree() {
//    clear(root);
//}
template<typename T>
void AVLTree<T>::show(Node<T> *node, ostream &ou) const {
    if (node) {
        show(node->left, ou);
//        node->data.display(ou);
        ou << node->data;
        show(node->right, ou);
    }
}

template<typename T>
void AVLTree<T>::show(ostream &ou) const {
    if (empty())
        ou << "该树为空！无法打印\n";
    else show(root, ou);
}

template<typename T>
void AVLTree<T>::show(Node<T> *node) const {
    if (node) {
        show(node->left);
        node->data.display(cout);
        show(node->right);
    }
}

template<typename T>
void AVLTree<T>::show() const {
    if (empty())
        cout << "该树为空！无法打印\n";
    else show(root);
}

template<typename T>
void AVLTree<T>::Balancing(Node<T> *node) {
    if (node && node->parent) {
        node->parent->balance += node->isLR();
        if (num > 2 && node->parent->balance) {
            //结点数num>2才会出现不平衡的情况
            //node->parent->balance+node->isLR()!=0树高才会增加
            Node<T> *C = node, *LRC = node->parent, *P = LRC->parent;
            //在以上条件下，C, LRC, P都不会为空
            P->balance += LRC->isLR();//更新P的平衡因子
            while (abs(P->balance) < 2 && P != root) {
                C = LRC;
                LRC = P;
                P = P->parent;
                P->balance += LRC->isLR();
            }
            if (abs(P->balance) > 1) {//平衡因子不平衡，需要进行旋转
                if (P->balance * LRC->balance < 0) {//异号，需要进行两次旋转
                    if (LRC->balance > 0) R(C);
                    else L(C);
                    swap(C, LRC);//此时LRC与C的结点位置已经互换
                }
                if (P->balance > 0) {//再进行一轮旋转
                    R(LRC);
                } else L(LRC);
            }
        }
    }
}

template<typename T>
bool AVLTree<T>::add(const T &data) {
    Node<T> *node = insert(data);
    if (node) {
        Balancing(node);
        return true;
    } else return false;
}

template<typename T>
void AVLTree<T>::L(Node<T> *center) {
    //     |                       |
    //     N                       S
    //    / \     l-rotate(N)     / \
    //   L   S    ==========>    N   R
    //      / \                 / \
    //     M   R               L   M
    Node<T> *father = center->parent;
    if (center->hasLeft()) {//旋转中心有左节点需要由其父节点接管时
        father->right = center->left;
        center->left->parent = father;//断开NS，连接NM
    } else {
        father->right = nullptr;//断开NS
    }

    if (father->isLR() == 1) {//旋转中心结点的父节点为左子
        father->parent->left = center;
        center->parent = father->parent;
    } else if (father->isLR() == -1) {//旋转中心结点的父节点为右子
        father->parent->right = center;
        center->parent = father->parent;
    } else {//当旋转中心结点的父节点为根时
        root = center;
        root->parent = 0;
    }
    center->left = father;
    father->parent = center;//断开SM，连接SN
    //接下来调整平衡因子
    if (abs(father->balance) > 1) {
        //  此时是结点node的父节点不平衡
        // 一步旋转就平衡的情况  此时father->balance=-2;
        //对于center->balance的讨论，又分为两种情况
        if (center->balance < -1) {//center->balance=-2
            center->balance = 0;
            father->balance = 1;
        } else // center->balance=1/-1;
            father->balance = center->balance = 0;
    } else {//先左旋再右旋  又分三种种情况，node结点的平衡因子是否为0，不为0时node结点和父节点的平衡因子是否同号，
        if (center->balance == 0) {//此时 father->balance=-1
            center->balance = 1;
            father->balance = 0;
        } else if (father->balance * center->balance > 0) // 同号时，father->balance=center->balance=-1;
            father->balance = center->balance = 1;
        else {//不同号时，father->balance=-1，center->balance=1;
            father->balance = 0;
            center->balance = 2;
        }
    }
}

template<typename T>
void AVLTree<T>::R(Node<T> *center) {
    //       |                   |
    //       N                   S
    //      / \   r-rotate(N)   / \
    //     S   R  ==========>  L   N
    //    / \                     / \
    //   L   M                   M   R
    Node<T> *father = center->parent;
    if (center->hasRight()) {//旋转中心有右节点需要由其父节点接管时
        father->left = center->right;
        center->right->parent = father;//断开NS，连接NM
    } else {
        father->left = nullptr;//断开NS
    }

    if (father->isLR() == 1) {//旋转中心结点的父节点为左子
        father->parent->left = center;
        center->parent = father->parent;
    } else if (father->isLR() == -1) {//旋转中心结点的父节点为右子
        father->parent->right = center;
        center->parent = father->parent;
        root->parent = 0;
    } else {//当旋转中心结点的父节点为根时
        root = center;
    }
    center->right = father;
    father->parent = center;//断开SM，连接SN
    //接下来调整平衡因子
    if (abs(father->balance) > 1) {
        //  此时是结点node的父节点不平衡
        //一步旋转就平衡的情况  此时father->balance=2,
        //对于center->balance的讨论，又分为两种情况
        if (center->balance > 1) {//center->balance=2
            center->balance = 0;
            father->balance = -1;
        } else // center->balance=1;
            father->balance = center->balance = 0;
    } else {//先右旋再左旋  又分三种情况，node结点的平衡因子是否为0，不为0时node结点和父节点的平衡因子是否同号，
        if (center->balance == 0) {//此时 father->balance=1
            center->balance = -1;
            father->balance = 0;
        } else if (father->balance * center->balance > 0) // 同号时，father->balance=center->balance=1;
            father->balance = center->balance = -1;
        else {//不同号时，father->balance=1，center->balance=-1;
            father->balance = 0;
            center->balance = -2;
        }
    }
}


template<typename T>
Node<T> *AVLTree<T>::begin() {
    Node<T> *node = root;
    if (node) {
        while (node->last()) {
            node = node->last();
        }
    }
    return node;
}


template<typename T>
const Node<T> *AVLTree<T>::Root() const {
    return root;
}


#endif //LBMSS_LIBRARY_BOOK_MANAGEMENT_SYSTEM_SIMULATION__AVLTREE_H
