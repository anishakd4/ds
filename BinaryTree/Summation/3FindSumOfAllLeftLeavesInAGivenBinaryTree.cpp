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

int leftLeavesSum(Node* root){
    int ans = 0;
    if(root == NULL){
        return 0;
    }

    if(root->left && root->left->left == NULL && root->left->right == NULL){
        ans = ans + root->left->data;
    }

    return (ans + leftLeavesSum(root->left) + leftLeavesSum(root->right));

}

int main(){

    struct Node *root         = newNode(20); 
    root->left                = newNode(9); 
    root->right               = newNode(49); 
    root->right->left         = newNode(23); 
    root->right->right        = newNode(52); 
    root->right->right->left  = newNode(50); 
    root->left->left          = newNode(5); 
    root->left->right         = newNode(12); 
    root->left->right->right  = newNode(12); 

    cout << "Sum of left leaves is "<< leftLeavesSum(root); 

    return 0;
}