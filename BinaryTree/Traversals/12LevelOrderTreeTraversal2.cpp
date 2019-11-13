#include<iostream>
#include<queue>

using namespace std;

struct Node{
    int data;
    struct Node *left, *right;
};

Node* newNode(int data){
    Node* new_node = new Node;
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}   

void printLevelOrder(Node* root){

    cout << "Level Order traversal of binary tree is: "<<endl; 

    if(root == NULL){
        return;
    }

    queue<Node *> q;
    q.push(root);

    while(!q.empty()){
        Node *temp = q.front();
        cout<<temp->data<<" ";
        q.pop();

        if(temp->left != NULL){
            q.push(temp->left);
        }

        if(temp->right != NULL){
            q.push(temp->right);
        }
    }

    cout<<endl;

}

int main(){

    Node *root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5);

    printLevelOrder(root); 

    return 0;
}