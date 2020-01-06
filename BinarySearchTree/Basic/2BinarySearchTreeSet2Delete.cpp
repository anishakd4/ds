#include<iostream>

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

void inorder(Node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

Node* insert(Node* root, int k){
    if(root == NULL){
        return newNode(k);
    }

    if(root->data > k){
        root->left = insert(root->left, k);
    }

    if(root->data < k){
        root->right = insert(root->right, k);
    }

    return root;
}

Node* deleteNode(Node* root, int k){
    if(root == NULL){
        return NULL;
    }

    if(k < root->data){
        root->left = deleteNode(root->left, k);
    }else if(k > root->data){
        root->right = deleteNode(root->right, k);
    }else{
        if(root->left == NULL && root->right == NULL){
            return NULL;
        }else if(root->left == NULL){
            return root->right;
        }else if(root->right == NULL){
            return root->left;
        }

        Node* temp = root->right;
        Node* parent = root;
        while(temp->left != NULL){
            parent = temp;
            temp = temp->left;
        }

        parent->left = temp->right;
        root->data = temp->data;
    }

    return root;
}

int main(){

    struct Node* root = NULL; 
    root = insert(root, 50); 
    root = insert(root, 30); 
    root = insert(root, 20); 
    root = insert(root, 40); 
    root = insert(root, 70); 
    root = insert(root, 60); 
    root = insert(root, 80); 
  
    printf("Inorder traversal of the given tree \n"); 
    inorder(root);
  
    printf("\nDelete 20\n"); 
    root = deleteNode(root, 20); 
    printf("Inorder traversal of the modified tree \n"); 
    inorder(root); 
  
    printf("\nDelete 30\n"); 
    root = deleteNode(root, 30); 
    printf("Inorder traversal of the modified tree \n"); 
    inorder(root); 
  
    printf("\nDelete 50\n"); 
    root = deleteNode(root, 50); 
    printf("Inorder traversal of the modified tree \n"); 
    inorder(root); 
    return 0;
}