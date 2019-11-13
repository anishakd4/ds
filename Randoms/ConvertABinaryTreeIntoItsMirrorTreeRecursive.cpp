#include<iostream>

using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return new_node;
}

void mirror(Node* root){
    if(root == NULL){
        return;
    }
    mirror(root->left);
    mirror(root->right);

    struct Node* temp;
    temp = root->left;
    root->left = root->right;
    root->right = temp;
}

void inorder(struct Node* node){
    if(node == NULL){
        return;
    }
    inorder(node->left);
    cout<<node->data<<" ";
    inorder(node->right);
}

int main(){

    struct Node *root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5);  
    
    cout << "Inorder traversal of the constructed tree is: " << endl; 
    inorder(root); 
    cout<<endl;
      
    mirror(root);  
      
    cout << "\nInorder traversal of the mirror tree is: "<<endl;  
    inorder(root); 
    cout<<endl;
       
    return 0;
}