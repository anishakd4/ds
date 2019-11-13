#include<iostream>
#include<vector>

using namespace std;

struct Node{
    int data;
    struct Node *left, *right;
};

struct Node* getNode(int data){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return new_node;
}

void preorderTraversal(struct Node* root){
    if(!root){
        return;
    }
    cout << root->data << " "; 
    preorderTraversal(root->left); 
    preorderTraversal(root->right); 
}

void storeInorderTraversal(struct Node* root, vector<int> &arr){
    if(!root){
        return;
    }
    storeInorderTraversal(root->left, arr);
    arr.push_back(root->data);
    storeInorderTraversal(root->right, arr);
}

void replaceNodeWithSum(struct Node* root,vector<int> arr, int &i){
    if(!root){
        return;
    }
    replaceNodeWithSum(root->left, arr, i);
    root->data = arr[i-1]+ arr[i+1];
    i++;
    replaceNodeWithSum(root->right, arr, i);
}

void replaceNodeWithSumUtil(struct Node* root){
    if(root == NULL){
        return;
    }

    vector<int> arr;
    arr.push_back(0);
    storeInorderTraversal(root, arr); 
    arr.push_back(0);   
    int i = 1; 
    replaceNodeWithSum(root, arr, i);
}

int main(){

    struct Node* root = getNode(1); 
    root->left = getNode(2);       
    root->right = getNode(3);      
    root->left->left = getNode(4); 
    root->left->right = getNode(5); 
    root->right->left = getNode(6); 
    root->right->right = getNode(7); 

    cout << "Preorder Traversal before tree modification: "<<endl; 
    preorderTraversal(root); 
    cout<<endl;
  
    replaceNodeWithSumUtil(root); 
  
    cout << "Preorder Traversal after tree modification: "<<endl; 
    preorderTraversal(root); 
    cout<<endl;

    return 0;
}