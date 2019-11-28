#include<iostream>

using namespace std;

struct Node{
    int data;
    Node *left, *right;
};

Node* newNode(int data){
    Node* new_node = new Node;
    new_node->right = new_node->left = NULL;
    new_node->data = data;
    return new_node;
}

void printOddNodesUtil(Node* root, bool isOdd){
    if(root == NULL){
        return;
    }

    if(isOdd){
        cout<<root->data<<" ";
    }

    printOddNodesUtil(root->left, !isOdd);
    printOddNodesUtil(root->right, !isOdd);
}

void printOddNodes(Node* root){
    bool isOdd = true;
    printOddNodesUtil(root, isOdd);
}

int main(){

    struct Node* root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 

    printOddNodes(root);
    cout<<endl;

    return 0;
}