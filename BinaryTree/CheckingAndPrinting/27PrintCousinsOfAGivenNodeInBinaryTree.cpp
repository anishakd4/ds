#include<iostream>

using namespace std;

struct Node{
    int data;
    Node *left, *right;
};

Node* newNode(int data){
    Node* new_node = new Node;
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return new_node;
}

int getLevel(Node* root, Node* node, int level){
    if(root ==  NULL){
        return 0;
    }
    if(node == root){
        return level;
    }

    int ans = getLevel(root->left, node, level + 1);
    if(ans != 0){
        return ans;
    }

    return getLevel(root->right, node, level + 1);
}

void printCousinsUtil(Node *root, Node *node, int level){
    if(root == NULL || level<2){
        return;
    }
    if(level == 2){
        if(root->left == node || root->right == node){
            return;
        }
        if(root->left){
            cout<<root->left->data<<" ";
        }
        if(root->right){
            cout<<root->right->data<<" ";
        }
    }else if(level > 2){
        printCousinsUtil(root->left, node, level-1);
        printCousinsUtil(root->right, node, level-1);
    }
}

void printCousins(Node* root, Node* node){
    int level = getLevel(root, node, 1);

    printCousinsUtil(root, node, level);
}

int main(){

    Node *root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->left->right->right = newNode(15); 
    root->right->left = newNode(6); 
    root->right->right = newNode(7); 
    root->right->left->right = newNode(8); 
  
    printCousins(root, root->left->right);
    cout<<endl;

    return 0;
}