#include<iostream>
#include<stack>

using namespace std;

struct Node{
    char data;
    Node *left, *right;
};

Node* newNode(char data){
    Node* new_node = new Node;
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return new_node;
}

void printTree( Node *root) { 
    if (!root) {
        return;
    }
    printTree(root->left); 
    cout << root->data <<" "; 
    printTree(root->right); 
} 

Node * convertExpression(string expression){
    stack<Node *> st;
    int i=0;

    st.push(newNode(expression[i]));

    while(i < expression.length()){
        if(expression[i] == '?'){
            i++;
            st.push(newNode(expression[i]));
        }else if(expression[i] == ':'){
            i++;
            st.push(newNode(expression[i]));

            Node *right = st.top();
            st.pop();
            Node *left = st.top();
            st.pop();

            Node *root = st.top();
            root->left = left;
            root->right = right;
            
        }
        i++;
    }

    return st.top();
}

int main(){

    string expression = "a?b?c:d:e"; 
    Node *root = convertExpression(expression); 

    printTree(root) ; 
    cout<<endl;

    return 0;
}