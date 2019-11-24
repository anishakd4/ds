#include<iostream>

using namespace std;

struct Node{
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int data){
    struct Node* new_node = new Node;
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return new_node;
}

int count(Node *root){
    if(root == NULL){
        return 0;
    }
    return (1 + count(root->left) + count(root->right));
}

int checkUtil(Node* root, int n, bool &res){
    if(root == NULL){
        return 0;
    }

    int c = checkUtil(root->left, n, res) + checkUtil(root->right, n, res) + 1;

    if(n-c == c){
        res = true;
    } 

    return c;
}

bool check(Node* root){
    int n = count(root);
    bool res = false;

    checkUtil(root, n, res);

    return res;
}

int main(){

    struct Node* root = newNode(5); 
    root->left = newNode(1); 
    root->right = newNode(6); 
    root->left->left = newNode(3); 
    root->right->left = newNode(7); 
    root->right->right = newNode(4); 
  
    check(root)?  printf("YES") : printf("NO");
    cout<<endl;

    return 0;
}