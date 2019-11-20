#include<iostream>

using namespace std;

struct Node{
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int data){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return new_node;
}

int height(Node* root){
    if(root == NULL){
        return 0;
    }
    int lHeight = height(root->left);
    int rHeight = height(root->right);

    if(lHeight > rHeight){
        return (lHeight + 1);
    }else{
        return (rHeight + 1);
    }
}

void printGivenLevel(struct Node* root, int i, bool check){
    if(root ==  NULL){
        return;
    }
    if(i == 1){
        cout<<root->data<<" ";
    }else{
        if(check){
            printGivenLevel(root->left, i-1, check);
            printGivenLevel(root->right, i-1, check);
        }else{
            printGivenLevel(root->right, i-1, check);
            printGivenLevel(root->left, i-1, check);
        }
    }
}

void printSpiral(struct Node* root){
    int h = height(root);

    bool check=false;
    for(int i=1; i<=h; i++){
        printGivenLevel(root, i, check);
        check = !check;
    }
}

int main(){

    struct Node* root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(7); 
    root->left->right = newNode(6); 
    root->right->left = newNode(5); 
    root->right->right = newNode(4); 

    printf("Spiral Order traversal of binary tree is \n"); 
    printSpiral(root); 
    cout<<endl;

    return 0;
}