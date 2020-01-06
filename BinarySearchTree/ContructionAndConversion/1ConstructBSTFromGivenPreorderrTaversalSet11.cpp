#include<iostream>

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

void inorder(Node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

Node* constructTreeUtil(int pre[], int &preIndex, int l, int r, int n){
    if(preIndex >= n || l > r){
        cout<<"enter"<<" : "<<l<<" : "<<r<<endl;
        return NULL;
    }

    Node* root = newNode(pre[preIndex]);
    cout<<root->data<<" : "<<l<<" : "<<r<<endl;
    preIndex = preIndex + 1;

    if(l == r){
        return root;
    }

    int i;
    for(i=l; i<=r; i++){
        if(pre[i] > root->data){
            break;
        }
    }

    root->left = constructTreeUtil(pre, preIndex, preIndex, i-1, n);
    root->right = constructTreeUtil(pre, preIndex, i, r, n);

    return root;
}

Node* constructTree(int pre[], int n){
    int preIndex = 0;
    return constructTreeUtil(pre, preIndex, 0, n - 1, n); 
}

int main(){

    int pre[] = {10, 5, 1, 7, 40, 50};  
    int size = sizeof( pre ) / sizeof( pre[0] );  
  
    Node *root = constructTree(pre, size);  
  
    cout<<"Inorder traversal of the constructed tree: \n";  
    inorder(root); 
    cout<<endl;

    return 0;
}