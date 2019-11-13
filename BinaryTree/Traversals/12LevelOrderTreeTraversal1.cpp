#include<iostream>

using namespace std;

class Node{
    public:
        int data;
        Node *left, *right;
};

Node* newNode(int data){
    Node* new_node = new Node();
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

int height(Node* root){
    if(root == NULL){
        return 0;
    }else{
        int lheight = height(root->left);
        int rheight = height(root->right);
        
        if(lheight > rheight){
            return (1 + lheight);
        }
        return (1 + rheight);
    }
}

void printGivenLevel(Node* root, int level){
    if(root == NULL){
        return;
    }

    if(level == 1){
        cout<<root->data<<" ";
    }else if(level > 1){
        printGivenLevel(root->left, level - 1);
        printGivenLevel(root->right, level - 1);
    }
}

void printLevelOrder(Node* root){
    cout << "Level Order traversal of binary tree is: "<<endl;  
    int h = height(root);

    for(int i=1; i<= h; i++){
        printGivenLevel(root, i);
    }
    cout<<endl;
}

int main(){

    Node* root = newNode(1);
    root->left = newNode(2);  
    root->right = newNode(3);  
    root->left->left = newNode(4);  
    root->left->right = newNode(5); 
    printLevelOrder(root); 
    return 0;
}