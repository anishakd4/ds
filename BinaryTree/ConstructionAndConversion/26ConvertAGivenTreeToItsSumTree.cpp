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

void printInorder(Node* root){
    if(root == NULL){
        return;
    }
    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}

int toSumTree(Node * root){
    
    if(root == NULL){
        return 0;
    }

    int old_val = root->data;

    root->data = toSumTree(root->left) + toSumTree(root->right);

    return old_val + root->data;
}

int main(){

    Node *root = NULL;  
    root = newNode(10);  
    root->left = newNode(-2);  
    root->right = newNode(6);  
    root->left->left = newNode(8);  
    root->left->right = newNode(-4);  
    root->right->left = newNode(7);  
    root->right->right = newNode(5);  
      
    toSumTree(root);  
       
    cout<<"Inorder Traversal of the resultant tree is: \n";  
    printInorder(root); 
    cout<<endl;

    return 0;
}