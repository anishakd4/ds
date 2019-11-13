#include<iostream>

using namespace std;

struct Node{
    int data;
    Node *left, *right;
};

struct Node* newNode(int data){
    struct Node* node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

bool treeContinuous(struct Node *node){
    if(node == NULL){
        return true;
    }
    if(node->left == NULL & node->right == NULL){
        return true;
    }
    if(node->left == NULL){
        return ((abs(node->data - node->right->data) == 1) && treeContinuous(node->right));
    }
    if(node->right == NULL){
        return ((abs(node->data - node->left->data) == 1) && treeContinuous(node->left));
    }

    return ((abs(node->data - node->right->data) == 1) 
            && treeContinuous(node->right) 
            && (abs(node->data - node->left->data) == 1) 
            && treeContinuous(node->left));
}

int main(){

    struct Node *root = newNode(3); 
    root->left = newNode(2); 
    root->right = newNode(4); 
    root->left->left = newNode(1); 
    root->left->right = newNode(3); 
    root->right->right = newNode(5); 
    treeContinuous(root)?  cout << "Yes" : cout << "No";
    cout<<endl;

    return 0;
}