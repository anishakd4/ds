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

Node* insert(Node* root, int data){
    if(root == NULL){
        return newNode(data);
    }

    if(data < root->data){
        root->left = insert(root->left, data);
    }

    if(data > root->data){
        root->right = insert(root->right, data);
    }

    return root;
}

int main(){

    struct Node* root = NULL; 
    root = insert(root, 50); 
    insert(root, 30); 
    insert(root, 20); 
    insert(root, 40); 
    insert(root, 70); 
    insert(root, 60); 
    insert(root, 80); 
   
    inorder(root); 
    cout<<endl;

    return 0;
}