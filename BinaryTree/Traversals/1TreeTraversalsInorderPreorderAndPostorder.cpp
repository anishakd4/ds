#include<iostream>

using namespace std;

struct Node{
    int data;
    struct Node *left, *right;
    Node(int data){
        this->data = data;
        left = right = NULL;
    }
};

void printInorder(Node* root){
    if(root == NULL){
        return;
    }
    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}

void printPreorder(Node* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    printPreorder(root->left);
    printPreorder(root->right);
}

void printPostorder(Node* root){
    if(root == NULL){
        return;
    }
    printPostorder(root->left);
    printPostorder(root->right);
    cout<<root->data<<" ";
}

int main(){

    struct Node *root = new Node(1); 
    root->left             = new Node(2); 
    root->right         = new Node(3); 
    root->left->left     = new Node(4); 
    root->left->right = new Node(5);  
  
    cout << "Preorder traversal of binary tree is: "<<endl; 
    printPreorder(root); 
    cout<<endl;
  
    cout << "Inorder traversal of binary tree is: "<<endl; 
    printInorder(root); 
    cout<<endl;
  
    cout << "Postorder traversal of binary tree is: "<<endl; 
    printPostorder(root);
    cout<<endl;

    return 0;
}