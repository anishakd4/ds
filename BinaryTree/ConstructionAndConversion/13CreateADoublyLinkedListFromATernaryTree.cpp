#include<iostream>

using namespace std;

struct Node{
    int data;
    Node *left, *right, *middle;
};

Node* newNode(int data){
    Node* new_node = new Node;
    new_node->data = data;
    new_node->left = new_node->right = new_node->middle = NULL;
    return new_node;
}

void printList(Node* head){
    cout<<"Doubly linkd list: "<<endl;
    while(head){
        cout<<head->data<<" ";
        head = head->right;
    }
    cout<<endl;
}

void push(Node* &tail, Node* root){
    if(tail == NULL){
        tail = root;
        root->left = root->right = root->middle = NULL;
        return;
    }
    tail->right = root;
    root->left = tail;
    root->right = tail->middle = NULL;
    tail = root;
}

void TernaryTreeToList(Node *root, Node* &head_ref, Node* &tail){
    if(root == NULL){
        return;
    }

    Node* left = root->left; 
    Node* middle = root->middle; 
    Node* right = root->right;

    if(head_ref == NULL){
        head_ref = root;
    }

    push(tail, root);

    TernaryTreeToList(left, head_ref, tail);
    TernaryTreeToList(middle, head_ref, tail);
    TernaryTreeToList(right, head_ref, tail);
}

int main(){

    Node* root = newNode(30); 
  
    root->left = newNode(5); 
    root->middle = newNode(11); 
    root->right = newNode(63); 
  
    root->left->left = newNode(1); 
    root->left->middle = newNode(4); 
    root->left->right = newNode(8); 
  
    root->middle->left = newNode(6); 
    root->middle->middle = newNode(7); 
    root->middle->right = newNode(15); 
  
    root->right->left = newNode(31); 
    root->right->middle = newNode(55); 
    root->right->right = newNode(65); 
  
    Node* head = NULL; 
    Node* tail = NULL; 
  
    TernaryTreeToList(root, head, tail); 
  
    printList(head); 

    return 0;
}