#include <iostream>
#include <queue>
#include "TreeNode_Class.h"
using namespace std;

void preorder(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";

    for (int i = 0; i < root->children.size(); i++)
    {
        preorder(root->children[i]);
    }
}

void postorder(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }

    for (int i = 0; i < root->children.size(); i++)
    {
        postorder(root->children[i]);
    }

    cout << root->data << " ";
}

void printLevelWise(TreeNode<int> *root)
{
    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);

    while (pendingNodes.size() != 0)
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();

        cout << front->data << ":";

        for (int i = 0; i < front->children.size(); i++)
        {
            if (i == front->children.size() - 1)
            {
                cout << front->children[i]->data;
            }
            else
            {
                cout << front->children[i]->data << ",";
            }
            pendingNodes.push(front->children[i]);
        }
        cout << endl;
    }
}

void printAtLevelK(TreeNode<int> *root, int k)
{
    if (root == NULL)
    {
        return;
    }

    if (k == 0)
    {
        cout << root->data << endl;
        return;
    }

    for (int i = 0; i < root->children.size(); i++)
    {
        printAtLevelK(root->children[i], k - 1);
    }
}

TreeNode<int> *takeInputLevelWise()
{
    int rootData;
    cout << "Enter root data " << endl;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);

    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);

    while (pendingNodes.size() != 0)
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();

        cout << "Enter the number of children of " << front->data << endl;
        int numOfChild;
        cin >> numOfChild;

        for (int i = 0; i < numOfChild; i++)
        {
            cout << "Enter the " << i << "th child of " << front->data << endl;
            int childData;
            cin >> childData;
            TreeNode<int> *child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}

TreeNode<int> *takeInput()
{
    int rootData;
    cout << "Enter Data" << endl;
    cin >> rootData;

    TreeNode<int> *root = new TreeNode<int>(rootData);

    int n;
    cout << "Enter the number of children of " << rootData << endl;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        TreeNode<int> *child = takeInput();
        root->children.push_back(child);
    }
    return root;
}

void printTree(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << ":";
    for (int i = 0; i < root->children.size(); i++)
    {
        cout << root->children[i]->data << ",";
    }
    cout << endl;
    for (int i = 0; i < root->children.size(); i++)
    {
        printTree(root->children[i]);
    }
}

int NodeCount(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int count = 1;
    for (int i = 0; i < root->children.size(); i++)
    {
        int smallans = NodeCount(root->children[i]);
        count += smallans;
    }
    return count;
}

int countLeafNodes(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int count = 0;
    if (root->children.size() == 0)
    {
        return 1;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        int childLeafNode = countLeafNodes(root->children[i]);
        count += childLeafNode;
    }
    return count;
}

int sumOfNodes(TreeNode<int> *root)
{
    int sum = 0;
    sum += root->data;
    for (int i = 0; i < root->children.size(); i++)
    {
        int smallSum = sumOfNodes(root->children[i]);
        sum += smallSum;
    }
    return sum;
}

int Treeheight(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int height = 0;

    for (int i = 0; i < root->children.size(); i++)
    {
        int child_height = Treeheight(root->children[i]);
        if (child_height > height)
        {
            height = child_height;
        }
    }

    return height += 1;
}

int main()
{
    TreeNode<int> *root = takeInputLevelWise();
    printLevelWise(root);
    cout << endl
         << NodeCount(root) << endl;

    cout << "Number of nodes : " << NodeCount(root) << endl;
    cout << "Nodes at level 2 are: " << endl;
    printAtLevelK(root, 2);

    delete root;
    return 0;
}
// 1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0