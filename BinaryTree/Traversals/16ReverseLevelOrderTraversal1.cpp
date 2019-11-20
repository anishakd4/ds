#include<iostream>

using namespace std;

struct Node{
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int data){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data=data;
    new_node->left = new_node->right = NULL;
    return new_node;
}

int height(Node *node){
    if(node == NULL){
        return 0;
    }
    int lHeight = height(node->left);
    int rHeight = height(node->left);

    int maxH = max(lHeight, rHeight);
    
    return (maxH + 1);
}

void printGivenLevel(Node* root, int level){
    if (root == NULL)  
        return;  
    if (level == 1){
        cout << root->data << " ";  
    }else if (level > 1)  {  
        printGivenLevel(root->left, level - 1);  
        printGivenLevel(root->right, level - 1);  
    }
}

void reverseLevelOrder(Node *root){
    int h = height(root);  
    int i;  
    for (i=h; i>=1; i--) {
        printGivenLevel(root, i); 
    } 
}

int main(){

    struct Node *root = newNode(1);  
    root->left = newNode(2);  
    root->right = newNode(3);  
    root->left->left = newNode(4);  
    root->left->right = newNode(5); 

    cout << "Level Order traversal of binary tree is: "<<endl; 
    reverseLevelOrder(root);
    cout<<endl;

    return 0;
}