#include<iostream>
#include<map>
#include<stack>

using namespace std;

struct Node{
    int data;
    Node *left, *right;
};

Node* newNode(int data){
    Node* new_node = new Node;
    new_node->data = data;
    new_node->right = new_node->left = NULL;
    return new_node;
}

void printTopToBottomPath(Node *curr, map<Node*, Node*> parent){
    stack<Node *>st;

    while(curr){
        st.push(curr);
        curr = parent[curr];
    }

    while(!st.empty()){
        Node* temp = st.top();
        st.pop();
        cout<<temp->data<<" ";
    }
    cout<<endl;
}

void printRootToLeaf(Node* root){
    if(root == NULL){
        return;
    }

    stack<Node *>st;
    st.push(root);

    map<Node*, Node*> parent;
    parent[root] = NULL;

    while(!st.empty()){
        Node* temp = st.top();
        st.pop();

        if(temp->left == NULL && temp->right == NULL){
            printTopToBottomPath(temp, parent);
        }

        if (temp->right) { 
            parent[temp->right] = temp; 
            st.push(temp->right); 
        } 

        if (temp->left){
            parent[temp->left] = temp; 
            st.push(temp->left); 
        } 
    }
}

int main(){

    Node* root = newNode(10); 
    root->left = newNode(8); 
    root->right = newNode(2); 
    root->left->left = newNode(3); 
    root->left->right = newNode(5); 
    root->right->left = newNode(2); 

    printRootToLeaf(root);

    return 0;
}