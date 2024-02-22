
#ifndef LBMSS_NODE_HPP
#define LBMSS_NODE_HPP

template<typename T>
class Node {
public:
    T data;
    Node *left;
    Node *right;
    Node *parent;//父节点
    int balance;//平衡因子
    Node(const T &value, Node<T> *parent = nullptr) : data(value), left(nullptr), right(nullptr), parent(parent),
                                                      balance(0) {}

    int hasChild();//有几个孩子
    bool hasRight();//是否有右子
    bool hasLeft();//是否有左子
    int isLR();//是父节点左子（1）还是右子（-1），无父节点为0
    Node<T> *last();//返回中序遍历顺序的上一个结点
    Node<T> *next();//返回中序遍历顺序的下一个结点
    ~Node() = default;
};

template<typename T>
Node<T> *Node<T>::last() {
    Node<T> *node = this;
    if (node->hasLeft()) {//如果该结点有左子树，那么中序遍历的上一结点为左子树的最右结点
        // （先小然后一直大下去即最接近node->data的结点）
        node = node->left;
        while (node->hasRight()) {
            node = node->right;
        }
        return node;
    } else {//如果该结点没有左子树，那么中序遍历的上一结点需要向上寻找
        //如果该结点为右节点，那么上一结点应为其父节点
        //如果该结点为左结点，那么说明父节点还未被遍历，应继续向上寻找，直到为找到一个父节点为右节点为止
        while (node && node->isLR() != -1) {
            node = node->parent;
        }
        if (node) return node->parent;
        else nullptr;
    }
}

template<typename T>
Node<T> *Node<T>::next() {
    Node<T> *node = this;
    if (node->hasRight()) {//如果该结点有右子树，那么中序遍历的下一结点为右子树的最左结点
        // （先大然后一直小下去即最接近node->data的结点）
        node = node->right;
        while (node->hasLeft()) {
            node = node->left;
        }
        return node;
    } else {//如果该结点没有右子树，那么中序遍历的下一结点需要向上寻找
        //如果该结点为左节点，那么下一结点应为其父节点
        //如果该结点为右结点，那么说明父节点也已遍历完，继续向上寻找，直到为找到一个父节点为左节点为止
        while (node && node->isLR() != 1) {
            node = node->parent;
        }
        if (node) return node->parent;
        else nullptr;
    }
}


template<typename T>
int Node<T>::hasChild() {
    if (left != 0) {
        if (right != 0) return 2;
        else return 1;
    }
    return 0;
}

template<typename T>
int Node<T>::isLR() {
    if (parent == nullptr) return 0;
    if (parent->left == this) return 1;
    return -1;
}

template<typename T>
bool Node<T>::hasRight() {
    return right != nullptr;
}

template<typename T>
bool Node<T>::hasLeft() {
    return left != nullptr;
}


#endif //LBMSS_NODE_HPP
