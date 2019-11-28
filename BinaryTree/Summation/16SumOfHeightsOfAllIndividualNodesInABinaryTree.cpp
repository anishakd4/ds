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

int getTotalHeightUtil(Node* node, int &sum){
    if(node == NULL){
        return 0;
    }

    int lHeight = getTotalHeightUtil(node->left, sum);
    int rHeight = getTotalHeightUtil(node->right, sum);

    int height = 1 + max(lHeight, rHeight);

    sum = sum + height;

    return height;

}

int getTotalHeight(Node* node){
    if(node == NULL){
        return 0;
    }
    int sum=0;
    getTotalHeightUtil(node, sum);
    return sum;
}

int main(){

    struct Node* root = newNode(1); 
  
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    printf("Sum of heights of all Nodes = %d", getTotalHeight(root)); 
    cout<<endl;

    return 0;
}