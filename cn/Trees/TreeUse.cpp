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
using namespace std;
#include "TreeNode.h"
#include <queue>

TreeNode<int> *takeInputLevelWise()
{
    int rootData;
    cout << "Enter root data: " << endl;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);

    queue<TreeNode<int> *> pendingNodes;

    pendingNodes.push(root);
    while (!pendingNodes.empty())
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter number of children of " << front->data << endl;
        int numChild;
        cin >> numChild;

        for (int i = 0; i < numChild; i++)
        {
            int childData;
            cout << "Enter " << i << "th child of " << front->data << endl;
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
    cout << "Enter data" << endl;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);

    int n;
    cout << "Enter num of children of " << rootData << endl;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        TreeNode<int> *child = takeInput();
        root->children.push_back(child);
    }
    return root;
}

void printTree(TreeNode<int> *node)
{
    if (node == NULL)
    {
        return;
    }
    cout << node->data << " : ";
    for (int i = 0; i < node->children.size(); i++)
    {
        cout << (node->children[i]->data) << ", ";
    }
    cout << endl;
    for (int i = 0; i < node->children.size(); i++)
    {
        printTree(node->children[i]);
    }
}

int numNodes(TreeNode<int> *node)
{
    if (node == NULL) // not needed but to handle edge cases
    {
        return 0;
    }
    int ans = 1;
    for (int i = 0; i < node->children.size(); i++)
    {
        ans += numNodes(node->children[i]);
    }
    return ans;
}

void printAtLevelK(TreeNode<int> *node, int level)
{
    if (level == 0) // not needed but to handle edge cases
    {
        cout << node->data << endl;
        return;
    }

    for (int i = 0; i < node->children.size(); i++)
    {
        printAtLevelK(node->children[i], level - 1);
    }
}

void preOrder(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    for (int i = 0; i < root->children.size(); i++)
    {
        preOrder(root->children[i]);
    }
}

void deleteTree(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }

    for (int i = 0; i < root->children.size(); i++)
    {
        deleteTree(root->children[i]);
    }
    delete root;
}

// 1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0
int main()
{
    TreeNode<int> *node = new TreeNode<int>(1);
    TreeNode<int> *node1 = new TreeNode<int>(2);
    TreeNode<int> *node2 = new TreeNode<int>(3);
    node->children.push_back(node1);
    node->children.push_back(node2);
    printTree(node);

    // TreeNode<int> *newRoot = takeInput();
    // printTree(newRoot);

    TreeNode<int> *newRoot = takeInputLevelWise();
    printTree(newRoot);

    int ans = numNodes(newRoot);
    cout << "NUM NODES:" << ans << endl;

    cout << "---------PREORDER---------" << endl;
    preOrder(newRoot);
    cout << endl;
    cout << "---------PREORDER---------" << endl;

    // This is one way
    // deleteTree(newRoot);

    // another way here is to use destructors
    delete newRoot;

    return 0;
}
