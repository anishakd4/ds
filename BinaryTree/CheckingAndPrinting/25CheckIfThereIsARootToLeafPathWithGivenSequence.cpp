#include<iostream>

using namespace std;

struct Node{
    int data;
    Node *left, *right;
};

Node* newnode(int data){
    Node* new_node = new Node;
    new_node->left = new_node->right = NULL;
    new_node->data = data;
    return new_node;
}

bool existPath(Node* root, int arr[], int n, int index){
    if(root == NULL){
        return (n == 0);
    }

    if((root->left == NULL && root->right == NULL) && (root->data == arr[index] && index == n-1)){
        return true;
    }

    return ((index < n && root->data == arr[index]) &&  (existPath(root->left, arr, n, index+1) ||  existPath(root->right, arr, n, index+1)));
}

int main(){

    int arr[] = {5, 8, 6, 7}; 

    int n = sizeof(arr)/sizeof(arr[0]); 

    struct Node *root = newnode(5); 
    root->left    = newnode(3); 
    root->right   = newnode(8); 
    root->left->left = newnode(2); 
    root->left->right = newnode(4); 
    root->left->left->left = newnode(1); 
    root->right->left = newnode(6); 
    root->right->left->right = newnode(7); 
  
    existPath(root, arr, n, 0)? cout << "Path Exists" : cout << "Path does not Exist"; 
    cout<<endl;
    
    return 0;
}