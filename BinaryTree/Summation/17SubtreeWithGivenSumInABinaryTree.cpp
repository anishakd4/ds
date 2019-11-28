#include<iostream>

using namespace std;

struct Node{
    int data;
    Node *left, *right;
};

Node* newnode(int data){
    Node* new_node = new Node;
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return new_node;
}

int sumSubtreeUtil(Node* node, bool &res, int sum){
    if(node == NULL){
        return 0;
    }

    int lSum = sumSubtreeUtil(node->left, res, sum);
    int rSum = sumSubtreeUtil(node->right, res, sum);
    
    if(sum == (node->data + lSum + rSum)){
        res = true;
    }

    return (node->data + lSum + rSum);
}

bool sumSubtree(Node* node, int sum){
    if(node == NULL){
        return false;
    }

    bool res = false;
    sumSubtreeUtil(node, res, sum);

    return res;
}

int main(){

    struct Node *root = newnode(8); 
    root->left    = newnode(5); 
    root->right   = newnode(4); 
    root->left->left = newnode(9); 
    root->left->right = newnode(7); 
    root->left->right->left = newnode(1); 
    root->left->right->right = newnode(12); 
    root->left->right->right->right = newnode(2); 
    root->right->right = newnode(11); 
    root->right->right->left = newnode(3); 
    int sum = 22; 
  
    if (sumSubtree(root, sum)) {
        cout << "Yes"; 
    }else{
        cout << "No";
    } 

    cout<<endl;

    return 0;
}