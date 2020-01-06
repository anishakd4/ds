#include<iostream>

using namespace std;

struct Node{
    int data;
    Node *left, *right;
};

struct Node* newNode(int data){
    struct Node* new_node = new Node;
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return new_node;
}

void printInorder(Node* root){
    if(root == NULL){
        return;
    }
    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}

void addSmallerUtil(Node* root, int &sum){
    if(root == NULL){
        return;
    }

    addSmallerUtil(root->left, sum);

    sum = sum + root->data;
    root->data = sum;
    
    addSmallerUtil(root->right, sum);
}

void addSmaller(Node* root){
    int sum = 0;
    addSmallerUtil(root, sum);
}

int main(){

    Node* root = newNode(9); 
    root->left = newNode(6); 
    root->right = newNode(15); 
  
    printf(" Original BST\n"); 
    printInorder(root); 
  
    addSmaller(root); 
  
    printf("\n BST To Binary Tree\n"); 
    printInorder(root);

    return 0;

}