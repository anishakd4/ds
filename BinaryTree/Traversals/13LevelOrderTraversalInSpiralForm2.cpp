#include<iostream>
#include<stack>

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

void printSpiral(Node* root){
    if(root == NULL){
        return;
    }

    stack<Node *> s1, s2;
    s1.push(root);

    while(!s1.empty() || !s2.empty()){

        while(!s1.empty()){
            struct Node* temp = s1.top();
            s1.pop();
            cout<<temp->data<<" ";

            if(temp->right){
                s2.push(temp->right);
            }
            if(temp->left){
                s2.push(temp->left);
            }
        }

        while(!s2.empty()){
            struct Node* temp = s2.top();
            s2.pop();
            cout<<temp->data<<" ";

            if(temp->left){
                s1.push(temp->left);
            }
            if(temp->right){
                s1.push(temp->right);
            }
        }
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

    cout << "Spiral Order traversal of binary tree is \n"; 
    printSpiral(root); 
    cout<<endl;

    return 0;
}