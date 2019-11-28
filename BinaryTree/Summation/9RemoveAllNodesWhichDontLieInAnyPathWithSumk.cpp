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

void print(Node* root){
    if(root == NULL){
        return;
    }
    print(root->left);
    cout<<root->data<<" ";
    print(root->right);
}

bool isLeaf(Node* node){
    if(node != NULL && node->left == NULL && node->right == NULL){
        return true;
    }
    return false;
}

void prune(Node* root, int k){
    if(root == NULL){
        return;
    }

    prune(root->left, k-root->data);
    prune(root->right, k-root->data);

    if(root->left && isLeaf(root->left)){
        if(k > root->data + root->left->data){
            root->left = NULL;
        }
    }

    if(root->right && isLeaf(root->right)){
        if(k > root->data + root->right->data){
            root->right = NULL;
        }
    }

}

int main(){

    int k = 45; 
    
    struct Node *root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left = newNode(6); 
    root->right->right = newNode(7); 
    root->left->left->left = newNode(8); 
    root->left->left->right = newNode(9); 
    root->left->right->left = newNode(12); 
    root->right->right->left = newNode(10); 
    root->right->right->left->right = newNode(11); 
    root->left->left->right->left = newNode(13); 
    root->left->left->right->right = newNode(14); 
    root->left->left->right->right->left = newNode(15); 
    
  
    printf("Tree before truncation\n"); 
    print(root); 
    cout<<endl;
  
    prune(root, k);
  
    printf("Tree after truncation\n"); 
    print(root); 
    cout<<endl;

}