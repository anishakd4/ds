#include<iostream>

using namespace std;

struct Node{
    int data;
    struct Node *left, *right;
};

Node* newNode(int data){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return new_node;    
}

int heightAndSize(Node *root, int &size){
    if(root == NULL){
        return 0;
    }
    int l = heightAndSize(root->left, size);
    int r = heightAndSize(root->right, size);

    size++;

    return (max(l, r) + 1);
}

float density(Node* root){
    int size = 0;

    int height = heightAndSize(root, size);

    return ((float)size/(float)height);
}

int main(){

    Node* root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
  
    cout<<density(root)<<" "<<endl;

    return 0;
}