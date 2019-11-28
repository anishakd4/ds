#include<iostream>

using namespace std;

struct Node{
    int data;
    Node *left, *right;
};

Node* getNode(int data){
    Node* new_node = new Node;
    new_node->right = new_node->left = NULL;
    new_node->data = data;
    return new_node;
}

pair<int, int> sumOfLongRootToLeafPathUtil(Node* root){
    if(root == NULL){
        return (pair<int, int>(0, 0));
    }

    pair<int, int> lp = sumOfLongRootToLeafPathUtil(root->left);
    pair<int, int> rp = sumOfLongRootToLeafPathUtil(root->right);

    if(lp.first > rp.first){
        return (pair<int, int>(lp.first + 1, lp.second + root->data ));
    }else if(lp.first < rp.first){
        return (pair<int, int>(rp.first + 1, rp.second + root->data ));
    }else{
        return (pair<int, int>(rp.first + 1, max(lp.second, rp.second) + root->data ));
    }
}

int sumOfLongRootToLeafPath(Node *root){
    pair<int, int> pt = sumOfLongRootToLeafPathUtil(root);

    return pt.second;
}

int main(){

    Node* root = getNode(4);         
    root->left = getNode(2);         
    root->right = getNode(5);        
    root->left->left = getNode(7);   
    root->left->right = getNode(1);  
    root->right->left = getNode(2);  
    root->right->right = getNode(3); 
    root->left->right->left = getNode(6); 
  
    cout << "Sum = "<< sumOfLongRootToLeafPath(root)<<endl;

    return 0;
}