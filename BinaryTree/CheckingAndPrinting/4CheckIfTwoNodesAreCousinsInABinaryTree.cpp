#include<iostream>

using namespace std;

struct Node{
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int data){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->right = new_node->left = NULL;
    return new_node;
}

int level(Node* root, Node* a, int lev){
    if(root == NULL){
        return 0;
    }
    if(root == a){
        return lev;
    }

    int l = level(root->left, a, lev+1);

    if(lev > 0){
        return lev;
    }

    return level(root->right, a, lev +1);
}

bool isSibling(Node* root, Node* a, Node* b){
    if(root == NULL){
        return false;
    }

    return ((root->left ==a && root->right ==b) || (root->left == b && root->right == a) || isSibling(root->left, a, b) || isSibling(root->right, a, b));
}

bool isCousin(Node* root, Node* a, Node *b){
    if((level(root, a, 1) == level(root, b, 1)) && !isSibling(root, a, b)){
        return true;
    }else{
        return false;
    }
}

int main(){

    struct Node *root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->left->right->right = newNode(15); 
    root->right->left = newNode(6); 
    root->right->right = newNode(7); 
    root->right->left->right = newNode(8); 
  
    struct Node *Node1,*Node2; 
    Node1 = root->left->left; 
    Node2 = root->right->right; 
  
    isCousin(root, Node1, Node2)? puts("Yes"): puts("No"); 

    return 0;
}