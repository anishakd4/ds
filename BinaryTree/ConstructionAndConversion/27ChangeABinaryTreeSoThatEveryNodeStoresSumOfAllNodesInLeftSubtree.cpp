#include<iostream>
#include<stack>

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

    int leftSum = toSumTree(root->left);
    int rightSum = toSumTree(root->right);

    root->data = root->data + leftSum;

    return (root->data + rightSum);
}

int main(){

    struct Node *root = newNode(1);  
    root->left     = newNode(2);  
    root->right = newNode(3);  
    root->left->left = newNode(4);  
    root->left->right = newNode(5);  
    root->right->right = newNode(6);
      
    toSumTree(root);  
       
    cout<<"Inorder Traversal of the resultant tree is: \n";  
    printInorder(root); 
    cout<<endl;

    return 0;
}