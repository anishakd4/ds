#include<iostream>

using namespace std;

struct Node{
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int data){
    struct Node* new_node = new Node;
    new_node->data=data;
    new_node->left = new_node->right = NULL;
    return new_node;
}

void convertTree(Node *root){
    if(root == NULL){
        return;
    }
    convertTree(root->left);
    convertTree(root->right);
    if(root->left != NULL && root->right != NULL){
        root->data = root->left->data & root->right->data;
    }
}

void printInorder(Node* root){
    if(root == NULL){
        return;
    }
    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}

int main(){

    Node *root=newNode(0); 
    root->left=newNode(1); 
    root->right=newNode(0); 
    root->left->left=newNode(0); 
    root->left->right=newNode(1); 
    root->right->left=newNode(1); 
    root->right->right=newNode(1); 
    printf("\n Inorder traversal before conversion "); 
    printInorder(root); 
    cout<<endl;
  
    convertTree(root); 
  
    printf("\n Inorder traversal after conversion "); 
    printInorder(root); 
    cout<<endl;

    return 0;
}