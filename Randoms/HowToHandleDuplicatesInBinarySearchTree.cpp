#include<iostream>

using namespace std;

struct Node{
    int data;
    int count;
    Node *left, *right;
};

struct Node* newNode(int data){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data=data;
    new_node->count = 1;
    new_node->left = new_node->right = NULL;
    return new_node;
}

void inorder(struct Node* root){
    if(root != NULL){
        inorder(root->left);
        cout<<root->data<<"("<<root->count<<")";
        inorder(root->right);
    }
}

void insert(struct Node* node, int data){
    if(node == NULL){
        return;
    }

    if(node->data == data){
        (node->count)++;
        return;
    }
    if(data < node->data){
        if(node->left){
            insert(node->left, data);
        }else{
            node->left = newNode(data);
        }
    }else{
        if(node->right){
            insert(node->right, data);
        }else{
            node->right = newNode(data);
        }
    }    
}

struct Node* minValueNode(struct Node* node){
    while (node->left != NULL){
        node = node->left;
    }

    return node;
}

int main(){

    return 0;
}