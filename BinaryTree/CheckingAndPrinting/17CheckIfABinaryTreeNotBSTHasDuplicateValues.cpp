#include<iostream>
#include<unordered_set>

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

bool checkDupUtil(Node* root, unordered_set<int> &set){
    if(root == NULL){
        return false;
    }
    if(set.find(root->data) != set.end()){
        return true;
    }else{
        set.insert(root->data);
    }

    return (checkDupUtil(root->left, set) || checkDupUtil(root->right, set));
}

bool checkDup(Node *root){
    unordered_set<int> set;
    return checkDupUtil(root, set);
}

int main(){

    struct Node* root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(2); 
    root->left->left = newNode(3); 
    if (checkDup(root)) 
        printf("Yes"); 
    else
        printf("No");

    cout<<endl;

    return 0;
}