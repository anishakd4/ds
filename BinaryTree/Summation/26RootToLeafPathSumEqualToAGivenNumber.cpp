#include<iostream>

using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;
};

Node* newnode(int data){
    Node* new_node = new Node;
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return new_node;
}

bool isLeaf(Node* node){
    if(node != NULL && node->right == NULL && node->left == NULL){
        return true;
    }
    return false;
}

bool hasPathSum(Node* node, int sum){
    if(node == NULL){
        return false;
    }

    if(isLeaf(node) && sum == node->data){
        return true;
    }

    return (hasPathSum(node->left, sum - node->data) || hasPathSum(node->right, sum - node->data));
}

int main(){
    
    int sum = 21;  

    Node *root = newnode(10);  
    root->left = newnode(8);  
    root->right = newnode(2);  
    root->left->left = newnode(3);  
    root->left->right = newnode(5);  
    root->right->left = newnode(2);  
      
    if(hasPathSum(root, sum))  
        cout << "There is a root-to-leaf path with sum " << sum<<endl;  
    else
        cout << "There is no root-to-leaf path with sum " << sum<<endl;

    return 0;
}