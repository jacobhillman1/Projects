#ifndef AVLTREE_H
#define AVLTREE_H
#include "avlnode.h"
#include <fstream>
#include <iostream>

using namespace std;

template<class T>
class AvlTree
{
private:
    AvlNode<T>* root;

public:
    AvlTree() : root(nullptr) {}
    AvlTree(const AvlTree& rhs) : root(nullptr)
    {
        *this = rhs;
    }

    /*
     * Test if the tree if logically empty.
     * Return true if empty, false otherwise.
     */
    bool isEmpty() const
    {
        return root == nullptr;
    }

    /* Return true if the object passed is in the tree.*/
    bool contains(const T& x)
    {
        return contains(x, root);
    }

    /*
     * Return the object in the tree that matches the
     * object you are searching for
     */
    T& find(const T& x) const
    {
        return(find(x, root));
    }

    /*
     * Print subtree using inorder traversal
     * (For use with testing, always starts at root.
     */
    void printTree() const
    {
        AvlNode<T>* t = root;
        if( t != nullptr )
        {
            printTree(t->left);
            cout << t->data << endl;
            printTree(t->right);
        }
    }

    ~AvlTree()
    {
        makeEmpty();
    }

    /*
     * Delete the entire tree.
     */
    void makeEmpty()
    {
        makeEmpty(root);
    }

    /*
     * Insert data into the tree.
     */
    void insert(const T& data)
    {
        insert(data, root);
    }

private:
    /*
     * Return the height of node t or -1 if nullptr.
     */
    int height(AvlNode<T>* t) const
    {
        return t == nullptr? -1 : t->height;
    }

    int max(int lhs, int rhs) const
    {
        return lhs > rhs ? lhs : rhs;
    }

    /*
     * Public method to test if an item is in a subtree.
     * x is the item to search for.
     */
    bool contains(const T& x, AvlNode<T>* t) const
    {
        if(t == nullptr)
            //If you've reached the end of a tree without
            //finding a match
            return false;
        else if(t->data > x)
            return contains(x, t->left);
        else if(t->data < x)
            return contains(x, t->right);
        //if the object is neither greater than or less than,
        //it's a match. Return true.
        else
            return true;
    }

    /* Return the object that is being searched for.
     * Under the assumption that it is known that
     * the tree contains the value.
     */
    T& find(const T& x, AvlNode<T>* t) const
    {
        {
            if(t->data > x)
                find(x, t->left);
            else if(t->data < x)
                find(x, t->right);
            //if the object is neither greater than or less than,
            //it's a match. Return true.
            else
                return t->data;
        }
    }

    /*
     * Internal method to insert into a subtree.
     * x is the item to instert.
     * t is the node that roots the subtree.
     * Set the new root of the subtree.
     */
    void insert(const T& x, AvlNode<T>*& t)
    {
        if(t == nullptr)
            t = new AvlNode<T>(x, nullptr, nullptr);

        else if(t->data > x)
        {
            insert(x, t->left); //recur to the left
            if(height(t->left) - height(t->right) == 2)
            {
                if(t->left->data > x)
                    rotateWithLeftChild(t);
                else
                    doubleWithLeftChild(t);
            }
        }

        else if(t->data < x)
        {
            insert(x, t->right);
            if(height(t->right) - height(t->left) == 2)
            {
                if(t->right->data < x)
                    rotateWithRightChild(t);
                else
                    doubleWithRightChild(t);
            }
        }

        t->height = max(height(t->left), height(t->right)) + 1;
    }

    /*
     * Rotate binary tree node with left child.
     * For AVL trees, this is a single rotation for case 1.
     * Update heights, then set new root.
     */
    void rotateWithLeftChild(AvlNode<T>*& k2)
    {
        AvlNode<T>* k1 = k2->left;
        k2->left = k1->right;
        k1->right = k2;
        k2->height = max(height(k2->left), height(k2->right)) + 1;
        k1->height = max(height(k1->left), height(k1->right)) + 1;
        k2 = k1;
    }

    /*
     * Rotate binary tree node with right child.
     * For AVL trees, this is a single rotation for case 4.
     * Update heights, then set new root.
     */
    void rotateWithRightChild(AvlNode<T>*& k2)
    {
        AvlNode<T>* k1 = k2->right;
        k2->right = k1->left;
        k1->left = k2;
        k2->height = max(height(k2->left), height(k2->right)) + 1;
        k1->height = max(height(k1->left), height(k1->right)) + 1;
        k2 = k1;
    }

    /*
     * Double rotate binary tree node: first left child
     * with its right child, then node k3 with new left child.
     * For AVL trees, this is a double rotation for case 2.
     * Update heights, set new root.
     */
    void doubleWithLeftChild(AvlNode<T>*& k1)
    {
        rotateWithRightChild(k1->left);
        rotateWithLeftChild(k1);
    }

    /*
     * Double rotate binary tree node: first right child
     * with its left child, then node k1 with new right child.
     * For AVL trees, this is a double rotation for case 3.
     * Update heights, set new root.
     */
    void doubleWithRightChild(AvlNode<T>*& k1)
    {
        rotateWithLeftChild(k1->right);
        rotateWithRightChild(k1);
    }

    /*
     * Print subtree using inorder traversal
     */
    void printTree(AvlNode<T> *t) const
    {
        if( t != NULL )
        {
            printTree(t->left);
            cout << t->data << endl;
            printTree(t->right);
        }
    }

    /*
     * Delete everything in the subtree of t, including t.
     */
    void makeEmpty(AvlNode<T> * & t)
    {
        if( t != nullptr )
        {
            makeEmpty(t->left);
            makeEmpty(t->right);
            delete t;
        }
        t = nullptr;
    }
};

#endif // AVLTREE_H
