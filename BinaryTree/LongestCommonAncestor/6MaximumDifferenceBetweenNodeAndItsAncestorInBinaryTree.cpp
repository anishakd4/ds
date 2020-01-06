#include<iostream>

using namespace std;

struct Node{
    int data;
    Node *left, *right;
};

Node* newNode(int data){
    Node* new_node = new Node;
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return new_node;
}

void inorder(Node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int maxDiffUtil(Node* node, int &res){
    if(node == NULL){
        return INT_MAX;
    }
    
    if(node->left == NULL && node->right == NULL){
        return node->data;
    }

    int val = min(maxDiffUtil(node->left, res), maxDiffUtil(node->right, res));

    res = max(res, node->data - val);

    return min(val, node->data);
}

int maxDiff(Node* root){
    int res  = INT_MIN;

    maxDiffUtil(root, res);

    return res;
}

int main(){

    Node* root; 
    root = newNode(8); 
    root->left = newNode(3); 
  
    root->left->left = newNode(1); 
    root->left->right = newNode(6); 
    root->left->right->left = newNode(4); 
    root->left->right->right = newNode(7); 
  
    root->right = newNode(10); 
    root->right->right = newNode(14); 
    root->right->right->left = newNode(13); 
  
    printf("Maximum difference between a node and its ancestor is : %d\n", maxDiff(root)); 

    return 0;
}