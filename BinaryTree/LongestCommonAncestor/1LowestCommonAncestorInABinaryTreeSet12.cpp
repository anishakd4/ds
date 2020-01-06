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

Node* findLCA(Node* root, int n1, int n2){
    if(root == NULL){
        return NULL;
    }

    if(root->data == n1 || root->data == n2){
        return root;
    }

    Node* l = findLCA(root->left, n1, n2);
    Node* r = findLCA(root->right, n1, n2);

    if(l && r){
        return root;
    }

    if(l == NULL && r == NULL){
        return NULL;
    }

    return (l != NULL ? l : r);
}

int main(){

    Node * root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left = newNode(6); 
    root->right->right = newNode(7); 
    cout << "LCA(4, 5) = " << findLCA(root, 4, 5)->data<<endl; 
    cout << "nLCA(4, 6) = " << findLCA(root, 4, 6)->data<<endl; 
    cout << "nLCA(3, 4) = " << findLCA(root, 3, 4)->data<<endl; 
    cout << "nLCA(2, 4) = " << findLCA(root, 2, 4)->data<<endl;

    return 0;
}