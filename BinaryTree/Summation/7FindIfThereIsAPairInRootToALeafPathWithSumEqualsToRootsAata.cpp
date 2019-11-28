#include<iostream>
#include<unordered_set>

using namespace std;

struct Node{
    int data;
    Node *left, *right;
};

Node* newnode(int data){
    Node* new_node = new Node;
    new_node->left = new_node->right = NULL;
    new_node->data = data;
    return new_node;
}

bool printPathUtil(Node* node, unordered_set<int> &set, int sum){
    if(node == NULL){
        return false;
    }

    if(set.find(sum-node->data) != set.end()){
        return true;
    }else{
        set.insert(node->data);
    }

    bool res = printPathUtil(node->left, set, sum) || printPathUtil(node->right, set, sum);

    set.erase(node->data);
    return res;
}

bool isPathSum(Node* root){
    unordered_set<int> set;

    return (printPathUtil(root->left, set, root->data) || printPathUtil(root->right, set, root->data));
}

int main(){

    struct Node *root = newnode(8); 
    root->left    = newnode(5); 
    root->right   = newnode(4); 
    root->left->left = newnode(9); 
    root->left->right = newnode(7); 
    root->left->right->left = newnode(1); 
    root->left->right->right = newnode(12); 
    root->left->right->right->right = newnode(2); 
    root->right->right = newnode(11); 
    root->right->right->left = newnode(3); 
    isPathSum(root)? cout << "Yes" : cout << "No"; 
    cout<<endl;
    return 0;
}