#include<iostream>

using namespace std;

struct Node{
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int data){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return new_node;
}

int height(Node* root){
    if(root == NULL){
        return 0;
    }
    int lHeight = height(root->left);
    int rHeight = height(root->right);

    if(lHeight > rHeight){
        return lHeight + 1;
    }else{
        return rHeight + 1;
    }
    
}

void printGivenLevel(Node* root, int level){
    if(root == NULL){
        return;
    }
    if(level == 1){
        cout<<root->data<<" ";
    }else{
        printGivenLevel(root->left, level-1);
        printGivenLevel(root->right, level-1);
    }
    
}

void printLevelOrder(Node *root){
    if(root == NULL){
        return;
    }

    int h = height(root);

    for(int i=1; i<=h; i++){
        printGivenLevel(root, i);
        cout<<endl;
    }
}

int main(){

    Node *root = newNode(1);  
    root->left = newNode(2);  
    root->right = newNode(3);  
    root->left->left = newNode(4);  
    root->left->right = newNode(5);  
    root->right->right = newNode(6);  
  
    printLevelOrder(root);  

    return 0;
}