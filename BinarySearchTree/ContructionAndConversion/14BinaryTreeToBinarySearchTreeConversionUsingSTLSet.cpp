#include<iostream>
#include<set>

using namespace std;

struct Node{
    int data;
    struct Node *left, *right;
};

Node* newNode(int data){
    Node* new_node = new Node;
    new_node->data = data;
    new_node->right = new_node->left = NULL;
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

void storeInorderInSet(Node* root, set<int> &st){
    if(root == NULL){
        return;
    }
    storeInorderInSet(root->left, st);
    st.insert(root->data);
    storeInorderInSet(root->right, st);
}

void setToBST(set<int> &st, Node* root){
    if(root == NULL){
        return;
    }
    setToBST(st, root->left);

    auto it = st.begin();
    root->data = *it;
    st.erase(it);

    setToBST(st, root->right);
}

void binaryTreeToBST(Node* root){
    set<int> st;

    storeInorderInSet(root, st);

    setToBST(st, root); 
}

int main(){

    Node* root = newNode(5); 
    root->left = newNode(7); 
    root->right = newNode(9); 
    root->right->left = newNode(10); 
    root->left->left = newNode(1); 
    root->left->right = newNode(6); 
    root->right->right = newNode(11); 
  
    binaryTreeToBST(root); 

    cout << "Inorder traversal of BST is: " << endl; 
    inorder(root); 
    cout<<endl;

    return 0;
}