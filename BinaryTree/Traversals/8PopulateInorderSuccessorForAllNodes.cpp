#include<iostream>

using namespace std;

class Node{
    public:
        int data;
        Node *left, *right, *next;
};

Node* newnode(int data){
    Node* new_node = new Node();
    new_node->data = data;
    new_node->left = new_node->right = new_node->next = NULL;
    return new_node;
}

void populateNextReverseInorder(Node* node, Node **next){
    if(node == NULL){
        return;
    }
    populateNextReverseInorder(node->right, next);
    node->next = *next;
    *next = node;
    populateNextReverseInorder(node->left, next);
}

void populateNext(Node* root){
    Node* next = NULL;
    populateNextReverseInorder(root, &next);
}

void inorder(Node *root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    if(root->next){
        cout<<root->data<<" -> "<<root->next->data<<" ";
    }else{
        cout<<root->data<<" -> -1"<<" ";
    }
    
    inorder(root->right);
}

int main(){

    Node *root = newnode(10);  
    root->left = newnode(8);  
    root->right = newnode(12);  
    root->left->left = newnode(3);  
   
    populateNext(root);  

    cout<<"Inorder: "<<endl;
    inorder(root);
    cout<<endl;

    return 0;
}