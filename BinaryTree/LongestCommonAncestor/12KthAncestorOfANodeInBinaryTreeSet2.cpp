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

bool kthAncestorDFS(Node* root, int node, int &k, Node* &parent){
    if(root == NULL){
        return false;
    }

    if(root->data == node){
        return true;
    }

    if( kthAncestorDFS(root->left, node, k, parent) ||  kthAncestorDFS(root->right, node, k, parent)){
        k--;
        if(k == 0){
            parent = root;
        }
        return true;
    }
    return false;
}

int main(){

    Node *root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
  
    int k = 2; 
    int node = 5; 
  
    Node* parent = NULL;
    kthAncestorDFS(root, node, k, parent); 
      
    if (parent) {
        cout<<parent->data;
    }else{
        cout << "-1";
    }

    cout<<endl;

    return 0;
}