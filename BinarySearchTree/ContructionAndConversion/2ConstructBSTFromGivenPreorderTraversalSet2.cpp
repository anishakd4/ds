#include<iostream>
#include<stack>

using namespace std;

class Node{
    public:
        int data;
        Node *left, *right;
};

Node* newNode(int data){
    Node* new_node = new Node();
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return new_node;
}

void printInorder(Node* root){
    if(root == NULL){
        return;
    }
    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}

Node* constructTree(int pre[], int n){
    stack<Node *> st;

    Node* root = newNode(pre[0]);
    st.push(root);

    for(int i=1; i<n; i++){
        Node* temp = NULL;

        while(!st.empty() && pre[i] > (st.top())->data){
            temp = st.top();
            st.pop();
        }

        if(temp != NULL){
            temp->right = newNode(pre[i]);  
            st.push(temp->right);
        }else{
            (st.top())->left = newNode(pre[i]);
            st.push((st.top())->left);
        }
    }
    return root;
}

int main(){

    int pre[] = {10, 5, 1, 7, 40, 50};  
    int size = sizeof( pre ) / sizeof( pre[0] );  
  
    Node *root = constructTree(pre, size);  
  
    cout<<"Inorder traversal of the constructed tree: \n";  
    printInorder(root);  
    cout<<endl;
    
    return 0;
}