#include<iostream>

using namespace std;

class Node{
    public:
        int data;
        Node *left, *right;
};

Node* newNode(int data){
    Node* new_node = new Node;
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return new_node;
}

void printArray(int ints[], int len) {
    int i;  
    for (i = 0; i < len; i++) {
        cout << ints[i] << " ";  
    }  
    cout << endl;  
}

void printPathsUtil(Node *root, int path[], int pathLen){
    if(root == NULL){
        return;
    }

    path[pathLen] = root->data;  
    pathLen++;  
      
    if (root->left == NULL && root->right == NULL){
        printArray(path, pathLen);  
    }else{
        printPathsUtil(root->left, path, pathLen); 
        printPathsUtil(root->right, path, pathLen);  
    } 
}

void printPaths(Node *root){
    int path[1000];
    printPathsUtil(root, path, 0);
}

int main(){

    Node *root = newNode(1);  
    root->left = newNode(2);  
    root->right = newNode(3);  
    root->left->left = newNode(4);  
    root->left->right = newNode(5);  
    
    printPaths(root);

    return 0;
}