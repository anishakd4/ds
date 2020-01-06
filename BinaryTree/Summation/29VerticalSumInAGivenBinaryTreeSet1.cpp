#include<iostream>
#include<map>

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

void verticalSumUtil(Node* root, int hd, map<int, int> &mapi){
    if(root == NULL){
        return;
    }

    mapi[hd] = mapi[hd] + root->data;

    verticalSumUtil(root->left, hd-1, mapi);
    verticalSumUtil(root->right, hd + 1, mapi);
}

void verticalSum(Node* root){
    if(root == NULL){
        return;
    }

    map<int, int> mapi;
    map<int, int> :: iterator it;

    verticalSumUtil(root, 0, mapi);

    for(it = mapi.begin(); it != mapi.end(); it++){
        cout<<it->first<<" : "<<it->second<<endl;
    }
}

int main(){

    Node *root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left = newNode(6); 
    root->right->right = newNode(7); 
    root->right->left->right = newNode(8); 
    root->right->right->right = newNode(9); 
  
    cout << "Following are the values of vertical sums with the positions of the columns with respect to root\n"; 
    verticalSum(root);
    cout<<endl;

    return 0;
}