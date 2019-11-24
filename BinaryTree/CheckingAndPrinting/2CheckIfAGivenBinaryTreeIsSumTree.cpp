#include<iostream>

using namespace std;

struct Node{
    int data;
    Node *left, *right;
};

Node* newNode(int data){
    struct Node* new_node = new Node;
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return new_node;
}

bool isLeaf(Node *node){
    if(node->left == NULL && node->right == NULL){
        return true;
    }
    return false;
}

bool isSumTree(Node* node){
    if(node == NULL || isLeaf(node)){
        return true;
    }

    if(isSumTree(node->left) && isSumTree(node->right)){
        int ls=0, rs=0;
        
        if(node->left == NULL){
            ls = 0;
        }else if(isLeaf(node->left)){
            ls = node->left->data;
        }else{
            ls = 2*(node->left->data);
        }

        if(node->right == NULL){
            rs = 0;
        }else if(isLeaf(node->right)){
            rs = node->right->data;
        }else{
            rs = 2*(node->right->data);
        }

        return (node->data == ls + rs);
    }
    return false;
}

int main(){

    struct Node *root  = newNode(26); 
    root->left         = newNode(10); 
    root->right        = newNode(3); 
    root->left->left   = newNode(4); 
    root->left->right  = newNode(6); 
    root->right->right = newNode(3); 

    if(isSumTree(root)) {
        printf("The given tree is a SumTree ");
    } else{
        printf("The given tree is not a SumTree ");
    } 
    cout<<endl;

    return 0;

}