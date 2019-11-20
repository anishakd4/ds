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

Node* insertLevelOrder(int arr[], int i, int n){
    Node* root= NULL;

    if(i < n){
        root = newNode(arr[i]);
        root->left = insertLevelOrder(arr, 2*i + 1, n);
        root->right = insertLevelOrder(arr, 2*i + 2, n);
    }
    return root;
}

void inOrder(Node* root){
    if(root == NULL){
        return;
    }

    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

int main(){

    int arr[] = {1, 2, 3, 4, 5, 6, 6, 6, 6 };
    int n = sizeof(arr)/sizeof(arr[0]);

    Node *root = insertLevelOrder(arr, 0, n);

    cout<<"Inorder traversal: "<<endl;
    inOrder(root); 
    cout<<endl;

    return 0;
}