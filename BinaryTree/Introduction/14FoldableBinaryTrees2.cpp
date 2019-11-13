#include<iostream>

using namespace std;

class Node{
    public:
        int data;
        Node *left, *right;
};

Node* newNode(int data){
    Node* new_node = new Node();
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return new_node;
}

bool isFoldableUtil(Node* a, Node* b){
    if(a == NULL && b == NULL){
        return true;
    }

    if(a == NULL || b == NULL){
        return false;
    }

    return (isFoldableUtil(a->left, b->right) && isFoldableUtil(a->right, b->left));
}

bool isFoldable(Node* root){
    if(root == NULL){
        return true;
    }

    return isFoldableUtil(root->left, root->right);
}

int main(){

    Node* root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->right = newNode(4); 
    root->right->left = newNode(5); 
  
    if (isFoldable(root) == true) { 
        cout << "tree is foldable"<<endl; 
    } else { 
        cout << "tree is not foldable"<<endl; 
    } 

}