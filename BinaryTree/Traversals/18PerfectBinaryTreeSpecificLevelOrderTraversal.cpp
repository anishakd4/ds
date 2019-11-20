#include<iostream>
#include<queue>

using namespace std;

struct Node{
    int data;
    Node*left, *right;
};

struct Node* newNode(int data){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return new_node;
}

void printSpecificLevelOrder(struct Node* root){
    if(root == NULL){
        return;
    }

    cout << root->data; 
  
    if (root->left != NULL) {
        cout << " " << root->left->data << " " << root->right->data;
    } 
  
    if (root->left->left == NULL) { 
        return; 
    }
  
    queue <Node *> q; 
    q.push(root->left); 
    q.push(root->right); 
  
    Node *first = NULL, *second = NULL;

    while(!q.empty()){
        first = q.front(); 
        q.pop(); 
        second = q.front(); 
        q.pop(); 
    
        cout << " " << first->left->data << " " << second->right->data; 
        cout << " " << first->right->data << " " << second->left->data; 
    
        if (first->left->left != NULL) { 
            q.push(first->left); 
            q.push(second->right); 
            q.push(first->right); 
            q.push(second->left); 
       } 
    }
}

int main(){

    Node *root = newNode(1); 
  
    root->left        = newNode(2); 
    root->right       = newNode(3); 
  
    root->left->left  = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left  = newNode(6); 
    root->right->right = newNode(7); 
  
    root->left->left->left  = newNode(8); 
    root->left->left->right  = newNode(9); 
    root->left->right->left  = newNode(10); 
    root->left->right->right  = newNode(11); 
    root->right->left->left  = newNode(12); 
    root->right->left->right  = newNode(13); 
    root->right->right->left  = newNode(14); 
    root->right->right->right  = newNode(15); 
  
    root->left->left->left->left  = newNode(16); 
    root->left->left->left->right  = newNode(17); 
    root->left->left->right->left  = newNode(18); 
    root->left->left->right->right  = newNode(19); 
    root->left->right->left->left  = newNode(20); 
    root->left->right->left->right  = newNode(21); 
    root->left->right->right->left  = newNode(22); 
    root->left->right->right->right  = newNode(23); 
    root->right->left->left->left  = newNode(24); 
    root->right->left->left->right  = newNode(25); 
    root->right->left->right->left  = newNode(26); 
    root->right->left->right->right  = newNode(27); 
    root->right->right->left->left  = newNode(28); 
    root->right->right->left->right  = newNode(29); 
    root->right->right->right->left  = newNode(30); 
    root->right->right->right->right  = newNode(31); 
  
    cout << "Specific Level Order traversal of binary tree is \n"; 
    printSpecificLevelOrder(root); 
    cout<<endl;

    return 0;
}