#include<iostream>
#include<stack>

using namespace std;

struct Node{
    char value;
    Node *left, *right;
};

struct Node* newNode(char value){
    struct Node* new_node = new Node;
    new_node->value = value;
    new_node->left = new_node->right = NULL;
    return new_node;
}

bool isOperator(char c){
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
        return true; 
    }
    return false; 
}

void inorder(Node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->value<<" ";
    inorder(root->right);
}

Node* constructTree(char postfix[]){
    stack<Node *> st;
    for(int i=0; i<strlen(postfix); i++){
        if(!isOperator(postfix[i])){
            struct Node* temp = newNode(postfix[i]);
            st.push(temp);
        }else{
            struct Node* temp = newNode(postfix[i]);
            temp->right = st.top();
            st.pop(); 
            temp->left = st.top();
            st.pop(); 

            st.push(temp);
        }
    }

    return st.top();
}

int main(){

    char postfix[] = "ab+ef*g*-"; 
    Node* root = constructTree(postfix); 
    cout<<"infix expression is: "<<endl;; 
    inorder(root); 
    cout<<endl;

    return 0;
}