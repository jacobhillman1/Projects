#include "treenode.h"

template<class T>
TreeNode<T>::TreeNode()
{
    left, right = nullptr;
}

template<class T>
TreeNode<T>::TreeNode(T data)
{
    this->data = data;
    left, right = nullptr;
}

