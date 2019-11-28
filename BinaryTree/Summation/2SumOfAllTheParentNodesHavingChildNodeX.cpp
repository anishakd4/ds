#include<iostream>

using namespace std;

struct Node{
    int data;
    Node *left, *right;
};

Node* getNode(int data){
    Node* new_node = new Node;
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return new_node;
}

void sumOfParentOfXUtil(Node *root, int &sum, int x){
    if(root == NULL){
        return;
    }

    if((root->left && root->left->data == x) || (root->right && root->right->data == x)){
        sum = sum + root->data;
    }

    sumOfParentOfXUtil(root->left, sum, x); 
    sumOfParentOfXUtil(root->right, sum, x);
}

int sumOfParentOfX(Node *root, int x){
    int sum = 0;
    sumOfParentOfXUtil(root, sum, x);
    return sum;
}

int main(){

    Node *root = getNode(4);           
    root->left = getNode(2);          
    root->right = getNode(5);         
    root->left->left = getNode(7);     
    root->left->right = getNode(2);   
    root->right->left = getNode(2); 
    root->right->right = getNode(3); 
      
    int x = 2; 
      
    cout << "Sum = "<< sumOfParentOfX(root, x);
    cout<<endl;

    return 0;
}