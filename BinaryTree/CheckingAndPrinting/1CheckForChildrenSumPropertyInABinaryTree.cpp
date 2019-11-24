#include<iostream>

using namespace std;

struct Node{
    int data;
    Node *left, *right;
};

Node* newNode(int data){
    struct Node* new_node = new Node;
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return new_node;
}

bool isSumProperty(Node *root){
    if(root == NULL || (root->left == NULL && root->right == NULL)){
        return true;
    }else{
        int left_data = 0, right_data = 0;

        if(root->left){
            left_data = root->left->data;
        }
        if(root->right){
            right_data = root->right->data;
        }

        return ((root->data == left_data + right_data) && isSumProperty(root->left) && isSumProperty(root->right));
    }
}

int main(){

    struct Node *root = newNode(10); 
    root->left     = newNode(8); 
    root->right = newNode(2); 
    root->left->left = newNode(3); 
    root->left->right = newNode(5); 
    root->right->right = newNode(2); 

    if(isSumProperty(root)) {
        cout << "The given tree satisfies the children sum property "<<endl; 
    }else{
        cout << "The given tree does not satisfy the children sum property "<<endl;
    } 

    return 0; 
}