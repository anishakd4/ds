#include<iostream>

using namespace std;

class Node{
    public:
        int data;
        Node *left, *right;
};

Node* newNode(int data){
    Node* new_node = new Node();
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return new_node;
}

bool isLeaf(Node* node){
    if(node != NULL && node->left == NULL && node->right == NULL){
        return true;
    }
    return false;
}

void treePathsSumUtil(Node* node, int &sum, int val){
    if(node == NULL){
        return;
    }

    val = val * 10;
    val = val + node->data;

    if(isLeaf(node)){
        sum = sum + val;
        return;
    }

    treePathsSumUtil(node->left, sum, val);
    treePathsSumUtil(node->right, sum, val);
}

int treePathsSum(Node* node){
    if(node == NULL){
        return 0;
    }
    int sum = 0;

    treePathsSumUtil(node, sum, 0);

    return sum;
}

int main(){

    Node *root = newNode(6);  
    root->left = newNode(3);  
    root->right = newNode(5);  
    root->left->left = newNode(2);  
    root->left->right = newNode(5);  
    root->right->right = newNode(4);  
    root->left->right->left = newNode(7);  
    root->left->right->right = newNode(4);  
    cout<<"Sum of all paths is "<<treePathsSum(root)<<endl;;

    return 0;
}