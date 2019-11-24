#include<iostream>

using namespace std;

struct Node{
    int data;
    Node *left, *right;
};

struct Node* newNode(int data){
    Node* new_node = new Node;
    new_node->left = new_node->right = NULL;
    new_node->data = data;
    return new_node;
}

void printMiddleLevel(Node* a, Node* b){
    if(a == NULL || b == NULL){
        return;
    }

    if(b->left == NULL && b->right == NULL){
        cout<<a->data<<" ";
    }

    if(b->left){
        printMiddleLevel(a->left, b->left->left);
    }

    if(b->right){
        printMiddleLevel(a->right, b->left->left);
    }
    
}

int main(){

    Node* n1 = newNode(1); 
    Node* n2 = newNode(2); 
    Node* n3 = newNode(3); 
    Node* n4 = newNode(4); 
    Node* n5 = newNode(5); 
    Node* n6 = newNode(6); 
    Node* n7 = newNode(7); 
  
    n2->left = n4; 
    n2->right = n5; 
    n3->left = n6; 
    n3->right = n7; 
    n1->left = n2; 
    n1->right = n3; 
  
    printMiddleLevel(n1, n1);
    cout<<endl;

    return 0;
}