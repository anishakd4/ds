#include<iostream>

using namespace std;

struct Node{
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int data){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return new_node;
}

void printNthPostorder(Node *node, int &count, int cnt){
    if(node == NULL){
        return;
    }
    if(count >= cnt){
        return;
    }
    printNthPostorder(node->left, count, cnt);
    printNthPostorder(node->right, count, cnt);
    count++;
    if(count == cnt){
        cout<<node->data<<endl;
        count++;
    }
}

int main(){

    struct Node* root = createNode(25); 
    root->left = createNode(20); 
    root->right = createNode(30); 
    root->left->left = createNode(18); 
    root->left->right = createNode(22); 
    root->right->left = createNode(24); 
    root->right->right = createNode(32);
  
    int n = 6; 
    int temp = 0;
  
    printNthPostorder(root, temp, n);

    return 0;
}