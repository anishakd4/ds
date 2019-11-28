#include<iostream>

using namespace std;

struct Node{
    int data;
    Node *left, *right;
};

struct Node* newNode(int data){
    Node* new_node = new Node;
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return new_node;
}

int maxPathSumUtil(Node* root, int &res){
    if(root == NULL){
        return 0;
    }

    int lsum = maxPathSumUtil(root->left, res);
    int rsum = maxPathSumUtil(root->right, res);

    res = max(res, root->data + lsum + rsum);

    return (root->data + max(lsum, rsum));
}

int maxPathSum(Node* root){
    int res = 0;
    maxPathSumUtil(root, res);

    return res;
}

int main(){

    struct Node *root = newNode(-15); 
    root->left = newNode(5); 
    root->right = newNode(6); 
    root->left->left = newNode(-8); 
    root->left->right = newNode(1); 
    root->left->left->left = newNode(2); 
    root->left->left->right = newNode(6); 
    root->right->left = newNode(3); 
    root->right->right = newNode(9); 
    root->right->right->right= newNode(0); 
    root->right->right->right->left= newNode(4); 
    root->right->right->right->right= newNode(-1); 
    root->right->right->right->right->left= newNode(10); 
    cout << "Max pathSum of the given binary tree is "<< maxPathSum(root)<<endl; 

    return 0;
}