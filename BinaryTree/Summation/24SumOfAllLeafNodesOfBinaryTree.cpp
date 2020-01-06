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

void leafSum(Node* node, int &sum){
    if(node == NULL){
        return;
    }

    if(node->right == NULL && node->left == NULL){
        sum = sum + node->data;
    }

    leafSum(node->left, sum);
    leafSum(node->right, sum);
}

int main(){

    Node *root = newNode(1); 
    root->left = newNode(2); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right = newNode(3); 
    root->right->right = newNode(7); 
    root->right->left = newNode(6); 
    root->right->left->right = newNode(8); 
    
    int sum = 0; 
    leafSum(root, sum); 
    cout << sum << endl; 

    return 0;
}