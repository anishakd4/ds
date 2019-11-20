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

void iterativePreorder(Node* root){
    if(root == NULL){
        return;
    }

    stack<Node *> st;

    st.push(root);

    while(!st.empty()){
        struct Node* temp = st.top();
        st.pop();
        cout<<temp->data<<" ";

        if(temp->right){
            st.push(temp->right);
        }
        if(temp->left){
            st.push(temp->left);
        }
    }
}

int main(){

    struct Node *root = newNode(10); 
    root->left        = newNode(8); 
    root->right       = newNode(2); 
    root->left->left  = newNode(3); 
    root->left->right = newNode(5); 
    root->right->left = newNode(2); 

    cout<<"PreOrder: "<<endl;
    iterativePreorder(root); 
    cout<<endl;

    return 0;
}