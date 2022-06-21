#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <cmath>
#include <map>
#include <climits>
// climits for INT_MIN
#include <unordered_map>
#include <queue>
using namespace std;
#include "BinaryTreeNode.h"
#include "BinarySearchTree.h"

void printTree(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << ":";
    if (root->left != NULL)
    {
        cout << "L" << root->left->data;
    }
    if (root->right != NULL)
    {
        cout << "R" << root->right->data;
    }
    cout << endl;
    printTree(root->left);
    printTree(root->right);
}

BinaryTreeNode<int> *takeInputLevelWise()
{
    int rootData;
    cout << "Enter root data" << endl;
    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);

    while (!pendingNodes.empty())
    {
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();

        cout << "Enter Left child of " << front->data << endl;
        int leftChildData;
        cin >> leftChildData;
        if (leftChildData != -1)
        {
            BinaryTreeNode<int> *child = new BinaryTreeNode<int>(leftChildData);
            front->left = child;
            pendingNodes.push(child);
        }

        cout << "Enter Right child of " << front->data << endl;
        int rightChildData;
        cin >> rightChildData;
        if (rightChildData != -1)
        {
            BinaryTreeNode<int> *child = new BinaryTreeNode<int>(rightChildData);
            front->right = child;
            pendingNodes.push(child);
        }
    }

    return root;
}

BinaryTreeNode<int> *takeInput()
{
    int rootData;
    cout << "Enter data: " << endl;
    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    BinaryTreeNode<int> *leftChild = takeInput();
    BinaryTreeNode<int> *rightChild = takeInput();

    root->left = leftChild;
    root->right = rightChild;

    return root;
}

int numNodes(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + numNodes(root->left) + numNodes(root->right);
}

void inOrder(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

BinaryTreeNode<int> *buildTreeUtil(int *in, int *pre, int inS, int inE, int preS, int preE)
{
    cout << endl;
    cout << "****************************************************************" << endl;
    cout << inS << "  " << inE << "  " << preS << "  " << preE << endl;

    if (inS > inE)
    {
        return NULL;
    }

    int rootData = pre[preS];

    cout << "root->data : " << rootData << endl;
    cout << "---INORDER---" << endl;
    for (int i = inS; i <= inE; i++)
    {
        cout << in[i] << " ";
    }
    cout << endl;
    cout << "---POSTORDER---" << endl;
    for (int i = preS; i <= preE; i++)
    {
        cout << pre[i] << " ";
    }
    cout << endl;
    cout << "****************************************************************" << endl;
    cout << endl;

    int rootIndex = -1;
    for (int i = inS; i <= inE; i++)
    {
        if (in[i] == rootData)
        {
            rootIndex = i;
            break;
        }
    }

    int lInS = inS;
    int lInE = rootIndex - 1;
    int lPreS = preS + 1;
    int lPreE = lInE - lInS + lPreS;
    int rInS = rootIndex + 1;
    int rInE = inE;
    int rPreS = lPreE + 1;
    int rPreE = preE;

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    root->left = buildTreeUtil(in, pre, lInS, lInE, lPreS, lPreE);
    root->right = buildTreeUtil(in, pre, rInS, rInE, rPreS, rPreE);

    return root;
}

BinaryTreeNode<int> *buildTree(int *in, int *pre, int size)
{
    return buildTreeUtil(in, pre, 0, size - 1, 0, size - 1);
}

int height(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + max(height(root->left), height(root->right));
}

/*          *
          /   \
         *     *
        / \   / \
       *   * *   *

    height = log(n)
    T(n)= k(n) + 2T(n/2)  =  O(nlogn)


        *
         \
          *
           \
            *
             \
              *
               \
                *
    height = n;
    T(n)= k(n) + T(n-1)  =  O(n^2) = O(n * n) = O(n *height)

    conclusion: time complexity= n*height
    So if a bad tree with long height is given then higher time complexity and if a good tree with smallert height
    is given then better time complexity
*/
int diameter(BinaryTreeNode<int> *root)
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

// Time complexity: O(n)
//(n) = k(n)
pair<int, int> heightDiameter(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        pair<int, int> p;
        p.first = 0;
        p.second = 0;
        return p;
    }

    pair<int, int> leftAns = heightDiameter(root->left);
    pair<int, int> rightAns = heightDiameter(root->right);

    int leftDiameter = leftAns.second;
    int leftHeight = leftAns.first;
    int rightDiameter = rightAns.second;
    int rightHeight = rightAns.first;

    int height = 1 + max(leftHeight, rightHeight);
    int diameter = max(leftHeight + rightHeight, max(leftDiameter, rightDiameter));

    pair<int, int> p;
    p.first = height;
    p.second = diameter;

    return p;
}

int maximum(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return INT_MIN;
    }

    return max(root->data, max(maximum(root->left), maximum(root->right)));
}

int minimum(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return INT_MAX;
    }

    return min(root->data, min(minimum(root->left), minimum(root->right)));
}

/*          *
          /   \
         *     *
        / \   / \
       *   * *   *

    height = log(n)
    T(n)= k(n) + 2T(n/2)  =  O(nlogn)


        *
         \
          *
           \
            *
             \
              *
               \
                *
    height = n;
    T(n)= k(n) + T(n-1)  =  O(n^2) = O(n * n) = O(n *height)

    conclusion: time complexity= n*height
    So if a bad tree with long height is given then higher time complexity and if a good tree with smallert height
    is given then better time complexity
*/
bool isBST(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return true;
    }

    int leftMax = maximum(root->left);
    int rightMin = minimum(root->right);

    bool output = (root->data > leftMax) && (root->data <= rightMin) && isBST(root->left) && isBST(root->right);

    return output;
}

class IsBSTReturn
{
public:
    bool isBST;
    int min;
    int max;
};

/*
T(n) = 2*T(n/2)+k
going to each node and doing constant operations
O(n)
*/
IsBSTReturn isBST2(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        IsBSTReturn output;
        output.min = INT_MAX;
        output.max = INT_MIN;
        output.isBST = true;
        return output;
    }
    IsBSTReturn leftOutput = isBST2(root->left);
    IsBSTReturn rightOutput = isBST2(root->right);

    int minimum = min(root->data, min(leftOutput.min, rightOutput.min));
    int maximum = max(root->data, max(leftOutput.max, rightOutput.max));
    bool isBSTFinal = (root->data > leftOutput.max && root->data <= rightOutput.min && leftOutput.isBST && rightOutput.isBST);

    IsBSTReturn output;
    output.min = minimum;
    output.max = maximum;
    output.isBST = isBSTFinal;
    return output;
}

bool isBST3(BinaryTreeNode<int> *root, int min, int max)
{
    if (root == NULL)
    {
        return true;
    }

    if (root->data < min || root->data > max)
    {
        return false;
    }

    bool isLeftOk = isBST3(root->left, min, root->data - 1);
    bool isRightOk = isBST3(root->right, root->data, max);

    return isLeftOk && isRightOk;
}

vector<int> *getRootToNodePath(BinaryTreeNode<int> *root, int data)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == data)
    {
        vector<int> *output = new vector<int>();
        output->push_back(root->data);
        return output;
    }

    vector<int> *leftOutput = getRootToNodePath(root->left, data);

    if (leftOutput != NULL)
    {
        leftOutput->push_back(root->data);
        return leftOutput;
    }

    vector<int> *rightOutput = getRootToNodePath(root->right, data);

    if (rightOutput != NULL)
    {
        rightOutput->push_back(root->data);
        return rightOutput;
    }

    return NULL;
}

// 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
// 4 2 6 1 3 5 7 -1 -1 -1 -1 -1 -1 -1 -1
// 4 2 6 1 30 5 7 -1 -1 -1 -1 -1 -1 -1 -1
int main()
{
    // BinaryTreeNode<int> *root = new BinaryTreeNode<int>(1);
    // BinaryTreeNode<int> *node1 = new BinaryTreeNode<int>(2);
    // BinaryTreeNode<int> *node2 = new BinaryTreeNode<int>(3);

    // root->left = node1;
    // root->right = node2;
    // printTree(root);
    // delete root;

    // cout << "--------------------------------" << endl;
    // BinaryTreeNode<int> *root2 = takeInputLevelWise();
    // printTree(root2);
    // cout << "NumNodes : " << numNodes(root2) << endl;

    // cout << "------------INORDER-------------" << endl;
    // inOrder(root2);
    // cout << endl;
    // cout << "------------INORDER-------------" << endl;
    // delete root2;

    // cout << "--------------------------------Tree construct--------------------------------" << endl;
    // int in[] = {4, 2, 5, 1, 8, 6, 9, 3, 7};
    // int pre[] = {1, 2, 4, 5, 3, 6, 8, 9, 7};
    // BinaryTreeNode<int> *root3 = buildTree(in, pre, 9);
    // printTree(root3);
    // delete root3;
    // cout << endl;
    // cout << "--------------------------------Tree construct--------------------------------" << endl;

    // BinaryTreeNode<int> *root4 = takeInputLevelWise();
    // printTree(root4);
    // cout << "NUM: " << numNodes(root4) << endl;
    // pair<int, int> p = heightDiameter(root4);
    // cout << "height: " << p.first << endl;
    // cout << "Diameter: " << p.second << endl;

    // BinaryTreeNode<int> *root4 = takeInputLevelWise();
    // printTree(root4);
    // cout << "isBST: " << isBST(root4) << endl;
    // cout << "isBST3: " << isBST3(root4, INT_MIN, INT_MAX) << endl;

    // BinaryTreeNode<int> *root5 = takeInputLevelWise();
    // vector<int> *output = getRootToNodePath(root5, 8);
    // for (int i = 0; i < output->size(); i++)
    // {
    //     cout << output->at(i) << " ";
    // }
    // delete output;
    // delete root5;

    BST b;
    b.insert(10);
    b.insert(5);
    b.insert(20);
    b.insert(7);
    b.insert(3);
    b.insert(15);
    b.deleteData(10);
    b.printTree();

    return 0;
}

/*
for deletion:
d+d'+d' <2h O(h)

For balanced search tree insertion deletion search is of the O(height)
for balanced search tree it will be always of the O(log(n)) as the height is around log(n)
height is log(n)
*/