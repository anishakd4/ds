#include<iostream>

using namespace std;

struct Node{
    int data;
    Node *left, *right;
};

struct Node* newNode(int data){
    Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return new_node;
}

void printInorder(Node* root){
    if(root == NULL){
        return;
    }
    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}

void addGreaterUtil(Node* root, int &sum){
    if(root == NULL){
        return;
    }
    addGreaterUtil(root->right, sum);

    sum = sum + root->data;
    root->data = sum;

    addGreaterUtil(root->left, sum);
}

void addGreater(Node* root){
    int sum = 0;
    addGreaterUtil(root, sum);
}

int main(){

    Node* root = newNode(5);  
    root->left = newNode(2);  
    root->right = newNode(13);  
  
    cout << "Inorder traversal of the " << "given tree" << endl;  
    printInorder(root);  
    cout<<endl;
  
    addGreater(root);  
  
    cout << "Inorder traversal of the " << "modified tree" << endl;  
    printInorder(root);
    cout<<endl;

    return 0;
}