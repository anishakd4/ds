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

void inorder(Node *root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void printList(Node* root){
    while(root != NULL){
        cout<<root->data<<" ";
        root = root->right;
    }
}

void BinaryTree2DoubleLinkedList(Node *root, Node* &head, Node* &tail){
    if(root == NULL){
        return;
    }

    BinaryTree2DoubleLinkedList(root->left, head, tail);

    if(head == NULL){
        head = root;
        tail = root;
    }else{
        tail->right = root;
        root->left = tail;
        tail = root;
    }
    BinaryTree2DoubleLinkedList(root->right, head, tail);
}

int main(){

    Node *root = newNode(10);  
    root->left = newNode(12);  
    root->right = newNode(15);  
    root->left->left = newNode(25);  
    root->left->right = newNode(30);  
    root->right->left = newNode(36);  
  
    cout<<"Inorder Tree Traversal "<<endl;  
    inorder(root);  
    cout<<endl;

    Node *head = NULL; 
    Node *tail = NULL; 
    BinaryTree2DoubleLinkedList(root, head, tail);
 
    printList(head); 
    cout<<endl;

    return 0;
}