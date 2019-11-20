#include<iostream>

using namespace std;

struct Node{
    int data;
    Node *left, *right;
};

struct Node* newNode(int data){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
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

Node* constructTreeUtil(int pre[], char preLN[], int &preIndex, int size){

    if(preIndex >= size){
        return NULL;
    }

    int index = preIndex;
    Node *root = newNode(pre[index]);
    preIndex++;

    if(preLN[index] == 'N'){
        root->left = constructTreeUtil(pre, preLN, preIndex, size);
        root->right = constructTreeUtil(pre, preLN, preIndex, size);
    }

    return root;
}

Node* constructTree(int pre[], char preLN[], int size){
    int preIndex = 0;
    return constructTreeUtil(pre, preLN, preIndex, size);
}

int main(){

    struct Node *root = NULL; 

    int pre[] = {10, 30, 20, 5, 15}; 
    char preLN[] = {'N', 'N', 'L', 'L', 'L'}; 
    int n = sizeof(pre)/sizeof(pre[0]); 
  
    root = constructTree (pre, preLN, n); 
  
    printf("Following is Inorder Traversal of the Constructed Binary Tree: \n"); 
    printInorder(root); 
    cout<<endl;

    return 0;
}