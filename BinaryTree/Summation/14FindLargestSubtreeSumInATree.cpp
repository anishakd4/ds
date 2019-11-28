#include<iostream>
#include<map>

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

int findLargestSubtreeSumUtil(Node* root, int &sum){
    if(root == 0){
        return 0;
    }

    int lSum = findLargestSubtreeSumUtil(root->left, sum);

    int rSum = findLargestSubtreeSumUtil(root->right, sum);

    if(sum < root->data + lSum + rSum){
        sum = root->data + lSum + rSum;
    }

    return (root->data + lSum + rSum);
}

int findLargestSubtreeSum(Node* root){
    if(root == NULL){
        return 0;
    }
    int sum = 0;
    
    findLargestSubtreeSumUtil(root, sum);

    return sum;
}

int main(){

    Node* root = newNode(1); 
    root->left = newNode(-2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left = newNode(-6); 
    root->right->right = newNode(2); 
  
    cout << findLargestSubtreeSum(root)<<endl;;
    return 0;   
}