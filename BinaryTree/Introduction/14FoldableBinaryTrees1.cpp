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

void mirror(Node* node){
    if(node == NULL){
        return;
    }

    struct Node* temp;

    mirror(node->left);
    mirror(node->right);

    temp = node->left;
    node->left = node->right;
    node->right = temp;
}

bool isStructSame(Node*a, Node*b){
    if(a == NULL && b== NULL){
        return true;
    }
    if(a != NULL && b!= NULL && isStructSame(a->left, b->left) && isStructSame(a->right, b->right)){
        return true;
    }
    return false;
}

bool isFoldable(Node* root){

    bool res;
    if(root == NULL){
        return true;
    }

    mirror(root->left);

    res = isStructSame(root->left, root->right);

    mirror(root->left);

    return res;
}

int main(){

    Node* root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->right->left = newNode(4); 
    root->left->right = newNode(5); 
  
    if (isFoldable(root)) { 
        cout << "tree is foldable"<<endl; 
    }else{ 
        cout << "tree is not foldable"<<endl; 
    }

    return 0;
}