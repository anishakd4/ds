#include<iostream>
#include<queue>

using namespace std;

struct Node{
    int data;
    Node *left, *right;
};

struct Node* newNode(int data){
    struct Node* new_node = new Node;
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return new_node;
}

bool isFullBinaryTree(Node* root){
    if(root == NULL){
        return true;
    }
    queue<Node *> q;
    q.push(root);

    while(!q.empty()){
        Node *temp = q.front();
        q.pop();

        if(temp->left == NULL && temp->right == NULL){
            continue;
        }

        if(temp->left != NULL && temp->right != NULL){
            q.push(temp->left);
            q.push(temp->right);
            continue;
        }

        return false;

    }

    return true;
}

int main(){

    Node* root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
  
    if (isFullBinaryTree(root)) 
        cout << "Yes"; 
    else
        cout << "No"; 

    cout<<endl;
  
    return 0;
}