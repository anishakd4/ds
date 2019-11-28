#include<iostream>

using namespace std;

struct Node{
    int data;
    Node *left, *right;
};

Node* getNode(int data){
    Node* new_node = new Node;
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return new_node;
}

int countSubtreesWithSumXUtil(Node* root, int x, int &count){
    if(root == NULL){
        return 0;
    }

    int lSum = countSubtreesWithSumXUtil(root->left, x, count);
    int rSum = countSubtreesWithSumXUtil(root->right, x, count);

    if(x == root->data + lSum + rSum){
        count++;
    }

    return (root->data + lSum + rSum);
}

int countSubtreesWithSumX(Node* root, int x){
    if(root == NULL){
        return 0;
    }

    int count = 0;

    countSubtreesWithSumXUtil(root, x, count);

    return count;
}

int main(){

    Node* root = getNode(5); 
    root->left = getNode(-10); 
    root->right = getNode(3); 
    root->left->left = getNode(9); 
    root->left->right = getNode(8); 
    root->right->left = getNode(-4); 
    root->right->right = getNode(7); 
  
    int x = 7; 
  
    cout << "Count = "<< countSubtreesWithSumX(root, x)<<endl; 

    return 0;
}