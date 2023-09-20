#include "binaryTreeNode.h"
class BST
{
    BinaryTreeNode<int> *root;

public:
    BST()
    {
        root = NULL;
    }

private:
    bool hasData(int data, BinaryTreeNode<int> *node)
    {
        if (node == NULL)
        {
            return false;
        }

        if (node->data == data)
        {
            return true;
        }
        else if (node->data > data)
        {
            return hasData(data, node->left);
        }
        else if (node->data < data)
        {
            return hasData(data, node->right);
        }
    }

public:
    bool hasData(int data)
    {
        return hasData(data, root);
    }
};