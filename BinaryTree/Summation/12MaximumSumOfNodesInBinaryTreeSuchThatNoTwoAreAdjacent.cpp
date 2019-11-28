#include<iostream>
#include<map>

using namespace std;

struct Node{
    int data;
    Node *left, *right;
};

struct Node* newNode(int data){
    Node* new_node = new Node;
    new_node->left = new_node->right = NULL;
    new_node->data = data;
    return new_node;
}

int getSumUtil(Node* node, map<Node*, int> mapi);

int sumOfGrandChildren(Node* node, map<Node*, int> mapi){
    int sum = 0;

    if(node->left){
        sum = sum + getSumUtil(node->left->left, mapi) + getSumUtil(node->left->right, mapi);
    }

    if(node->right){
        sum = sum + getSumUtil(node->right->left, mapi) + getSumUtil(node->right->right, mapi);
    }
    
    return sum;
}

int getSumUtil(Node* node, map<Node*, int> mapi){
    if(node == NULL){
        return 0;
    }

    if(mapi.find(node) != mapi.end()){
        return mapi[node];
    }

    int yesSum = node->data + sumOfGrandChildren(node, mapi);

    int noSum =  getSumUtil(node->left, mapi) + getSumUtil(node->right, mapi);

    mapi[node] = max(yesSum, noSum);

    return mapi[node];
}

int getMaxSum(Node* node){
    if(node == NULL){
        return 0;
    }
    map<Node*, int> mapi;
    return getSumUtil(node, mapi);
}

int main(){

    Node* root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->right->left = newNode(4); 
    root->right->right = newNode(5); 
    root->left->left = newNode(1); 
  
    cout << getMaxSum(root) << endl; 

    return 0;

}