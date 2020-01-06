#include<iostream>
#include<vector>

using namespace std;

struct Node{
    int data;
    struct Node *left, *right;
};

Node* newNode(int data){
    Node* new_node = new Node;
    new_node->left = new_node->right = NULL;
    new_node->data = data;
    return new_node;
}

bool findPath(Node* root, vector<int> &path, int k){
    if(root == NULL){
        return false;
    }

    path.push_back(root->data);

    if(root->data == k){
        return true;
    }

    if(findPath(root->left, path, k) || findPath(root->right, path, k)){
        return true;
    }

    path.pop_back();

    return false;
}

int findLCA(Node* root, int n1, int n2){
    vector<int> path1, path2;

    if(!findPath(root, path1, n1) || !findPath(root, path2, n2)){
        return -1;
    }

    int i;
    for(i=0; i<path1.size() && i<path2.size(); i++){
        if(path1[i] != path2[i]){
            break;
        }
    }

    return path1[i-1];
}

int main(){
    
    Node * root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left = newNode(6); 
    root->right->right = newNode(7); 
    cout << "LCA(4, 5) = " << findLCA(root, 4, 5)<<endl; 
    cout << "nLCA(4, 6) = " << findLCA(root, 4, 6)<<endl; 
    cout << "nLCA(3, 4) = " << findLCA(root, 3, 4)<<endl; 
    cout << "nLCA(2, 4) = " << findLCA(root, 2, 4)<<endl;

    return 0;
}