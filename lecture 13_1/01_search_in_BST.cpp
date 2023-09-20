#include <iostream>
using namespace std;
#include "BinarySearchTree.h"
#include <climits>
#include <vector>

vector<int> *returnPathToNode(BinaryTreeNode<int> *root, int k)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == k)
    {
        vector<int> *output = new vector<int>();
        output->push_back(root->data);
        return output;
    }

    vector<int> *leftPath = returnPathToNode(root->left, k);
    if (leftPath == NULL)
    {
        vector<int> *rightPath = returnPathToNode(root->right, k);
        if (rightPath)
        {
            rightPath->push_back(root->data);
            return rightPath;
        }
        else
        {
            return NULL;
        }
    }
    else
    {
        leftPath->push_back(root->data);
        return leftPath;
    }
}

int minimum(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return INT_MAX;
    }
    return min(root->data, min(minimum(root->left), minimum(root->right)));
}
int maximum(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return INT_MIN;
    }
    return max(root->data, max(maximum(root->left), maximum(root->right)));
}

class Pair
{
public:
    int minimum;
    int maximum;
    bool BST;
};

Pair isBSThelper(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        Pair p;
        p.minimum = minimum(root);
        p.maximum = maximum(root);
        p.BST = true;
        return p;
    }

    Pair left;
    Pair right;

    if (root->left)
    {
        left = isBSThelper(root->left);
    }
    if (root->right)
    {
        right = isBSThelper(root->right);
    }

    bool isBSTfinal = (left.BST && right.BST && root->data > left.maximum && root->data < right.minimum);

    Pair ans;
    ans.maximum = max(root->data, right.maximum);
    ans.minimum = min(root->data, left.minimum);
    ans.BST = isBSTfinal;

    return ans;
}

bool isBST(BinaryTreeNode<int> *root)
{
    return isBSThelper(root).BST;
}

int main()
{
    return 0;
}