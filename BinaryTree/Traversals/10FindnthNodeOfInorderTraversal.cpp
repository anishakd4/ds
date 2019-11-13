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

void printNthInorder(Node *node, int &count, int cnt){
    if(node == NULL){
        return;
    }
    if(count >= cnt){
        return;
    }
    printNthInorder(node->left, count, cnt);
    count++;
    if(count == cnt){
        cout<<node->data<<endl;
        count++;
    }
    printNthInorder(node->right, count, cnt);
}

int main(){

    struct Node* root = newNode(10); 
    root->left = newNode(20); 
    root->right = newNode(30); 
    root->left->left = newNode(40); 
    root->left->right = newNode(50); 
  
    int n = 4; 
    int temp = 0;
  
    printNthInorder(root, temp, 4);

    return 0;
}