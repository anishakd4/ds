#include<iostream>

using namespace std;

struct Node{
    int data;
    Node *left, *right;
};

Node* newNode(int data){
    struct Node* new_node = new Node;
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return new_node;
}

int areMirror(Node *a, Node* b){
    if(a == NULL && b == NULL){
        return true;
    }
    if(a == NULL || b == NULL){
        return false;
    }

    return ((a->data == b->data) && areMirror(a->left, b->right) && areMirror(a->right, b->left));
}

int main(){

    Node *a = newNode(1); 
    Node *b = newNode(1); 
    a->left = newNode(2); 
    a->right = newNode(3); 
    a->left->left  = newNode(4); 
    a->left->right = newNode(5); 
  
    b->left = newNode(3); 
    b->right = newNode(2); 
    b->right->left = newNode(5); 
    b->right->right = newNode(4); 
  
    areMirror(a, b)? cout << "Yes" : cout << "No"; 

    cout<<endl;

    return 0;
}