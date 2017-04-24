#ifndef TREENODE_H
#define TREENODE_H

template<class T>
class TreeNode
{
private:
    T data;
    TreeNode* left, right;
public:
    TreeNode();
    TreeNode(T data);
    template<class U> friend class AVLTree;
};

#endif // TREENODE_H
