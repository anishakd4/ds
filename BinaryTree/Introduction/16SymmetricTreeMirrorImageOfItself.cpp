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

bool isMirror(Node* a, Node* b){
    if(a == NULL && b == NULL){
        return true;
    }

    if(a != NULL && b != NULL && a->data == b->data && isMirror(a->left, b->right) && isMirror(a->right, b->left)){
        return true;
    }

    return false;
}

bool isSymmetric(Node* root){
    if(root == NULL){
        return true;
    }
    return isMirror(root->left, root->right);
}

int main(){

    Node *root        = newNode(1); 
    root->left        = newNode(2); 
    root->right       = newNode(2); 
    root->left->left  = newNode(3); 
    root->left->right = newNode(4); 
    root->right->left  = newNode(4); 
    root->right->right = newNode(3); 
  
    cout << isSymmetric(root)<<endl;

    return 0;
}