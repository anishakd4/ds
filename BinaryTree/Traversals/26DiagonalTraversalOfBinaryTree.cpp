#include<iostream>
#include <map>
#include<vector>

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

void diagonalPrintUtil(Node *root, int d, map<int, vector<int> > &mapi){
    if(root == NULL){
        return;
    }

    (mapi[d]).push_back(root->data);
    diagonalPrintUtil(root->left, d+1, mapi);
    diagonalPrintUtil(root->right, d, mapi);
}

void diagonalPrint(Node *root){
    map<int, vector<int> > mapi;
    diagonalPrintUtil(root, 0, mapi);

    for(auto t: mapi){
        for(int i=0; i<(t.second).size(); i++){
            cout<<(t.second)[i]<<" ";
        }
        cout<<endl;
    }
}

int main(){

    Node* root = newNode(8); 
    root->left = newNode(3); 
    root->right = newNode(10); 
    root->left->left = newNode(1); 
    root->left->right = newNode(6); 
    root->right->right = newNode(14); 
    root->right->right->left = newNode(13); 
    root->left->right->left = newNode(4); 
    root->left->right->right = newNode(7);

    diagonalPrint(root);

    return 0;
}