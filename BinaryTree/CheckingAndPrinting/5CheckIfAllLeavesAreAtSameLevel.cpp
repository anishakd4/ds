#include<iostream>

using namespace std;

struct Node{
    int data;
    Node *left, *right;
};

struct Node* newNode(int data){
    struct Node* new_node = new Node;
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return new_node;
}

bool isLeaf(Node* root){
    if(root->left == NULL && root->right == NULL){
        return true;
    }
    return false;
}

bool checkUtil(Node* root, int level, int &leafLevel){
    if(root == NULL){
        return true;
    }

    if(isLeaf(root)){
        if(leafLevel == 0){
            leafLevel = level;
            return true;
        }else{
            return (leafLevel == level);
        }
    }

    return (checkUtil(root->left, level + 1, leafLevel) &&  checkUtil(root->right, level + 1, leafLevel));

}

bool check(Node *root){
    int level = 1;
    int leafLevel = 0;

    return checkUtil(root, level, leafLevel);
}

int main(){

    struct Node *root = newNode(12); 
    root->left = newNode(5); 
    root->left->left = newNode(3); 
    root->left->right = newNode(9); 
    root->left->left->left = newNode(1); 
    root->left->right->left = newNode(1); 

    if (check(root)) 
        cout << "Leaves are at same level\n"; 
    else
        cout << "Leaves are not at same level\n";

    return 0;
}