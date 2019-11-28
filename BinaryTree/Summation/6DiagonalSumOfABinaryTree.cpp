#include<iostream>
#include<map>

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

void diagonalSum(Node* root, map<int, int> &mapi, int d){
    if(root == NULL){
        return;
    }
    mapi[d] = mapi[d] + root->data;

    diagonalSum(root->left, mapi, d+1);
    diagonalSum(root->right, mapi, d);

}

void diagonalSum(Node* root){
    map<int, int> mapi;

    diagonalSum(root, mapi, 0);

    map<int, int>::iterator it;

    for(it = mapi.begin(); it!= mapi.end(); it++){
        cout<<it->second<<" ";
    }
    cout<<endl;
}

int main(){

    struct Node* root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(9); 
    root->left->right = newNode(6); 
    root->right->left = newNode(4); 
    root->right->right = newNode(5); 
    root->right->left->right = newNode(7); 
    root->right->left->left = newNode(12); 
    root->left->right->left = newNode(11); 
    root->left->left->right = newNode(10); 
  
    diagonalSum(root);

    return 0;
}