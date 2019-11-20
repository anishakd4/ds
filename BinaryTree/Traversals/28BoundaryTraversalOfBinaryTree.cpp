#include<iostream>

using namespace std;

struct Node{
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int data){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return new_node;
}

void printLeftBoundary(Node* root){
    if(root == NULL){
        return;
    }

    if(root->left){
        cout<<root->data<<" ";
        printLeftBoundary(root->left);
    }else if(root->right){
        cout<<root->data<<" ";
        printLeftBoundary(root->right);
    }
}

void printRightBoundary(Node* root){
    if(root == NULL){
        return;
    }

    if(root->right){
        cout<<root->data<<" ";
        printRightBoundary(root->right);
    }else if(root->left){
        cout<<root->data<<" ";
        printRightBoundary(root->left);
    }
}

void printLeaves(Node* root){
    if(root == NULL){
        return;
    }
    printLeaves(root->left);

    if(!(root->left) && !(root->right)){
        cout<<root->data<<" ";
    }

    printLeaves(root->right);
}

void printBoundary(Node* root){
    if(root == NULL){
        return;
    }

    cout<<root->data<<" ";

    printLeftBoundary(root->left);
    printLeaves(root->left);
    printLeaves(root->right);
    printRightBoundary(root->right);

    cout<<endl;
}

int main(){

    struct Node* root = newNode(20); 
    root->left = newNode(8); 
    root->left->left = newNode(4); 
    root->left->right = newNode(12); 
    root->left->right->left = newNode(10); 
    root->left->right->right = newNode(14); 
    root->right = newNode(22); 
    root->right->right = newNode(25); 
  
    printBoundary(root);

    return 0;
}