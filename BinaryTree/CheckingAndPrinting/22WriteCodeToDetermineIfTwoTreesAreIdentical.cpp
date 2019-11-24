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

bool identicalTrees(Node* root1, Node* root2){
    if(root1 == NULL && root2 == NULL){
        return true;
    }

    if(root1 == NULL || root2 == NULL){
        return false;
    }

    return ((root1->data == root2->data) && identicalTrees(root1->left, root2->left) && identicalTrees(root1->right, root2->right));
}

int main(){

    Node *root1 = newNode(1);  
    Node *root2 = newNode(1);  

    root1->left = newNode(2);  
    root1->right = newNode(3);  
    root1->left->left = newNode(4);  
    root1->left->right = newNode(5);  
  
    root2->left = newNode(2);  
    root2->right = newNode(3);  
    root2->left->left = newNode(4);  
    root2->left->right = newNode(5);  
  
    if(identicalTrees(root1, root2))  
        cout << "Both tree are identical.";  
    else
        cout << "Trees are not identical.";  

    cout<<endl;

    return 0;
}