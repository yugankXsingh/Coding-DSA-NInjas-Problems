#include <iostream>
using namespace std;
#include "BinaryTree.h"
#include <queue>

void printTree(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << ": ";
    if (root->left != NULL)
    {
        cout << "L" << root->left->data << " ";
    }
    if (root->right != NULL)
    {
        cout << "R" << root->right->data << " ";
    }
    cout << endl;
    printTree(root->left);
    printTree(root->right);
}

BinaryTreeNode<int> *takeInput()
{
    int rootdata;
    cout << "Enter Data :" << endl;
    cin >> rootdata;
    if (rootdata == -1)
    {
        return NULL;
    }

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootdata);
    BinaryTreeNode<int> *leftChild = takeInput();
    BinaryTreeNode<int> *rightChild = takeInput();
    root->left = leftChild;
    root->right = rightChild;
    return root;
}

BinaryTreeNode<int> *takeInputLevelwise()
{
    int rootdata;
    cout << "Enter root data :" << endl;
    cin >> rootdata;
    if (rootdata == -1)
    {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootdata);
    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();

        cout << "Enter left child of " << front->data << endl;
        int leftchild;
        cin >> leftchild;
        if (leftchild != -1)
        {
            BinaryTreeNode<int> *child = new BinaryTreeNode<int>(leftchild);
            front->left = child;
            pendingNodes.push(child);
        }

        cout << "Enter right child of " << front->data << endl;
        int rightchild;
        cin >> rightchild;
        if (rightchild != -1)
        {
            BinaryTreeNode<int> *child = new BinaryTreeNode<int>(rightchild);
            front->right = child;
            pendingNodes.push(child);
        }
    }
    return root;
}

void printTreeLevelwise(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << front->data << ":";
        if (front->left != NULL)
        {
            cout << "L" << front->left->data;
            pendingNodes.push(front->left);
        }
        if (front->right != NULL)
        {
            cout << "R" << front->right->data;
            pendingNodes.push(front->right);
        }
        cout << endl;
    }
}

int countNodes(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftCount = countNodes(root->left);
    int rightCount = countNodes(root->right);
    return leftCount + rightCount + 1;
}

void mirrorBinaryTree(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }

    BinaryTreeNode<int> *temp = root->left;
    root->left = root->right;
    root->right = temp;

    mirrorBinaryTree(root->left);
    mirrorBinaryTree(root->right);
}

// TRAVERSALS

void inorder(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }

    if (root->left != NULL)
    {
        inorder(root->left);
    }

    cout << root->data << " ";

    if (root->right != NULL)
    {
        inorder(root->right);
    }
}

void preorder(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

/*******************************************************************************************************/

BinaryTreeNode<int> *buildTreeHelper(int *preorder, int *inorder, int preStart, int preEnd, int InStart, int InEnd)
{

    if (InStart > InEnd)
    {
        return NULL;
    }

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(preorder[preStart]);

    int rootIndex = -1;
    for (int i = InStart; i <= InEnd; i++)
    {
        if (inorder[i] == root->data)
        {
            rootIndex = i;
            break;
        }
    }

    int leftInStart = InStart;
    int leftInEnd = rootIndex - 1;
    int leftPreStart = preStart + 1;
    int leftPreEnd = leftInEnd - leftInStart + leftPreStart;

    int rightInStart = rootIndex + 1;
    int rightInEnd = InEnd;
    int rightPreStart = leftPreEnd + 1;
    int rightPreEnd = preEnd;

    // Building left subtree
    root->left = buildTreeHelper(preorder, inorder, leftPreStart, leftPreEnd, leftInStart, leftInEnd);
    // Building right subtree
    root->right = buildTreeHelper(preorder, inorder, rightPreStart, rightPreEnd, rightInStart, rightInEnd);
    return root;
}

BinaryTreeNode<int> *buildTree(int *preorder, int preLength, int *inorder, int inLength)
{
    return buildTreeHelper(preorder, inorder, 0, preLength - 1, 0, inLength - 1);
}

/*******************************************************************************************************/

class Pair
{
public:
    int height;
    int diameter;
};

Pair heightAndDiameter(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        Pair ans;
        ans.height = 0;
        ans.diameter = 0;
        return ans;
    }

    Pair left = heightAndDiameter(root->left);   // get left height and diameter of left subtree
    Pair right = heightAndDiameter(root->right); // get right height ans diameter of right subtree
    Pair ans;
    ans.height = 1 + max(left.height, right.height);
    ans.diameter = max(max(right.diameter, left.diameter), left.height + right.height);

    return ans;
}

int height(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }

    return 1 + max(height(root->left), height(root->right));
}

int diameter(BinaryTreeNode<int> *root) // time complexity is n*h
{
    if (root == NULL)
    {
        return 0;
    }

    int option1 = height(root->left) + height(root->right);
    int option2 = diameter(root->left);
    int option3 = diameter(root->right);

    return max(option1, max(option2, option3));
}

/******************************************************************************************************/
/******************************************************************************************************/

class Pair2
{
public:
    int height;
    bool isBalanced;
};

Pair2 isBalancedHelper(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        Pair2 ans;
        ans.height = 0;
        ans.isBalanced = true;
        return ans;
    }

    Pair2 leftTree = isBalancedHelper(root->left);   // Checking left subtree
    Pair2 rightTree = isBalancedHelper(root->right); // Checking right subtree
    Pair2 ans;

    ans.height = 1 + max(leftTree.height, rightTree.height);

    if (leftTree.isBalanced && rightTree.isBalanced)
    {
        ans.isBalanced = true;
    }
    else
    {
        ans.isBalanced = false;
    }

    if (abs(leftTree.height - rightTree.height) <= 1 && ans.isBalanced)
    {
        return ans;
    }
    else
    {
        ans.isBalanced = false;
    }

    return ans;
}

bool isBalanced(BinaryTreeNode<int> *root)
{
    // Write your code here
    Pair2 ans = isBalancedHelper(root);
    return ans.isBalanced;
}

/******************************************************************************************************/
/******************************************************************************************************/
void zigZagOrder(BinaryTreeNode<int> *root)
{
    // Write your code here
    if (root == NULL)
    {
        return;
    }

    deque<BinaryTreeNode<int> *> pendingNodes;
    // bool leftToRight = true;
    pendingNodes.push_back(root);
    // pendingNodes.push(NULL);
    int k = 0;

    while (!pendingNodes.empty())
    {

        int size = pendingNodes.size();
        for (int i = 0; i < size; i++)
        {
            if (k % 2 == 0)
            {
                BinaryTreeNode<int> *front = pendingNodes.front();
                cout << front->data << " ";
                pendingNodes.pop_front();
                if (front->left)
                    pendingNodes.push_back(front->left);
                if (front->right)
                    pendingNodes.push_back(front->right);
            }
            else
            {
                BinaryTreeNode<int> *back = pendingNodes.back();
                cout << back->data << " ";
                pendingNodes.pop_back();
                if (back->right)
                    pendingNodes.push_front(back->right);
                if (back->left)
                    pendingNodes.push_front(back->left);
            }
        }
        k++;
        cout << endl;
    }
}

/******************************************************************************************************/
/******************************************************************************************************/

int main()
{
    // BinaryTreeNode<int> *root = new BinaryTreeNode<int>(1);
    // BinaryTreeNode<int> *node1 = new BinaryTreeNode<int>(2);
    // BinaryTreeNode<int> *node2 = new BinaryTreeNode<int>(3);

    // root->left = node1;
    // root->right = node2;

    BinaryTreeNode<int> *root = takeInputLevelwise();
    printTreeLevelwise(root);
    cout << endl;
    cout << "Inorder : ";
    inorder(root);
    cout << endl;
    cout << "Number pf nodes : " << countNodes(root);
    Pair ans = heightAndDiameter(root);
    cout << endl
         << "height: " << ans.height << endl;

    cout << "diamter: " << ans.diameter << endl;
    cout << endl;

    cout << "Is Balanced : " << isBalanced(root) ? true : false;

    cout << endl
         << "Zig-Zag Traversal : ";
    zigZagOrder(root);

    return 0;
}

// 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
// 5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
