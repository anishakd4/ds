#include<iostream>
#include<vector>

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

void preorderTraversal(Node* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void inOrderTraveral(Node* root, vector<int> &arr){
    if(root == NULL){
        return;
    }
    inOrderTraveral(root->left, arr);
    arr.push_back(root->data);
    inOrderTraveral(root->right, arr);
}

void BSTToMinHeap(Node* root, vector<int> arr, int &i){
    if(root == NULL){
        return;
    }
    root->data = arr[i];
    i++;
    BSTToMinHeap(root->left, arr, i);
    BSTToMinHeap(root->right, arr, i);
}

void convertToMinHeapUtil(Node* root){
    vector<int> arr;

    inOrderTraveral(root, arr);
    int i=0;
    
    BSTToMinHeap(root, arr, i);
}

int main(){

    struct Node *root = getNode(4); 
    root->left = getNode(2); 
    root->right = getNode(6); 
    root->left->left = getNode(1); 
    root->left->right = getNode(3); 
    root->right->left = getNode(5); 
    root->right->right = getNode(7); 
  
    convertToMinHeapUtil(root); 

    cout << "Preorder Traversal:" << endl; 
    preorderTraversal(root);
    cout<<endl;

    return 0;
}