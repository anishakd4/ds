#include<iostream>

using namespace std;

struct Node{
    int data;
    Node *left , *right;
};

Node* newNode(int data){
    Node * temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

int findLevel(Node *root, int k, int level){
    if(root == NULL){
        return -1;
    }

    if(root->data == k){
        return level;
    }

    int l = findLevel(root->left, k, level + 1);
    if(l != -1){
        return l;
    }
    int r = findLevel(root->right, k, level + 1);
    return r;
}

Node* findLca(Node* root, int n1, int n2){
    if(root == NULL){
        return NULL;
    }

    if(root->data == n1 || root->data == n2){
        return root;
    }

    Node* l = findLca(root->left, n1, n2);
    Node* r = findLca(root->right, n1, n2);

    if(l != NULL && r != NULL){
        return root;
    }

    if(l == NULL && r == NULL){
        return NULL;
    }

    return ((l != NULL) ? l : r);
}

int findDistance(Node* root, int n1, int n2){
    Node *lca = findLca(root, n1, n2);

    int d1 = findLevel(lca, n1, 0); 
    int d2 = findLevel(lca, n2, 0); 
  
    return d1 + d2; 
}

int main(){

    Node* root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left = newNode(6); 
    root->right->right = newNode(7); 
    root->right->left->right = newNode(8); 
    cout << "Dist(4, 5) = " << findDistance(root, 4, 5) <<endl; 
    cout << "\nDist(4, 6) = " << findDistance(root, 4, 6) <<endl; 
    cout << "\nDist(3, 4) = " << findDistance(root, 3, 4) <<endl; 
    cout << "\nDist(2, 4) = " << findDistance(root, 2, 4) <<endl; 
    cout << "\nDist(8, 5) = " << findDistance(root, 8, 5) <<endl;
    return 0;
}