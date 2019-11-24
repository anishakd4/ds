#include<iostream>

using namespace std;

struct Node{
    int data;
    Node *left, *right;
};

struct Node* newNode(int data){
    struct Node* new_node = new Node;
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return new_node;
}

int diameterUtil(Node* root, int &ans){
    if(root == NULL){
        return 0;
    }

    int leftDia = diameterUtil(root->left, ans);
    int rightDia = diameterUtil(root->right, ans);

    ans = max(ans, 1 + leftDia + rightDia);

    return (1 + max(leftDia, rightDia));
}

int diameter(Node* root){
    if (root == NULL) {
        return 0;
    }
    
    int ans = 0;

    diameterUtil(root, ans);
    return ans;
}

int main(){

    struct Node* root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
  
    printf("Diameter is %d\n", diameter(root)); 

    return 0;
}