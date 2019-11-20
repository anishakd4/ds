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

void postOrderIterative(struct Node* root){
    if(root == NULL){
        return;
    }

    stack<Node *> s1, s2;
    s1.push(root);

    while(!s1.empty()){
        Node* temp = s1.top();
        s1.pop();

        s2.push(temp);

        if(temp->left){
            s1.push(temp->left);
        }
        if(temp->right){
            s1.push(temp->right);
        }
    }
    while (!s2.empty()){
        Node* temp = s2.top();
        s2.pop();
        cout<<temp->data<<" ";
    }
    

}

int main(){

    Node* root = NULL; 
    root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left = newNode(6); 
    root->right->right = newNode(7); 
  
    postOrderIterative(root);
    cout<<endl;

    return 0;
}