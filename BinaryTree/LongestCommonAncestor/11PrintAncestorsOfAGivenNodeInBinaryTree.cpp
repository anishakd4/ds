#include<iostream>

using namespace std;

struct Node{
    int data;
    Node *left, *right;
};

Node* newnode(int data){
    Node* new_node = new Node;
    new_node->left = new_node->right = NULL;
    new_node->data = data;
    return new_node;
}

bool printAncestors(Node* root, int k){
    if(root == NULL){
        return false;
    }

    if(root->data == k){
        return true;
    }

    if(printAncestors(root->left, k) || printAncestors(root->right, k)){
        cout<<root->data<<" ";
        return true;
    }

    return false;
}

int main(){

    struct Node* root = newnode(1); 
    root->left        = newnode(2); 
    root->right       = newnode(3); 
    root->left->left  = newnode(4); 
    root->left->right = newnode(5); 
    root->left->left->left  = newnode(7); 
    
    printAncestors(root, 7);
    cout<<endl;

    return 0;

}