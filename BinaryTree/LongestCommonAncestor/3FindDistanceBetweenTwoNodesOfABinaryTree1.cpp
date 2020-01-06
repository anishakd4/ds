#include<iostream>

using namespace std;

struct Node{
    int data;
    Node *left, *right;
};

Node* newNode(int data){
    Node* temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

int findLevel(Node* root, int k, int level){
    if(root == NULL){
        return -1;
    }

    if(root->data == k){
        return level;
    }

    int l = findLevel(root->left, k, level+1); 

    if(l != -1){
        return l;
    }

    int r = findLevel(root->right, k, level+1); 

    return r;
}

Node* findDistanceUtil(Node* root, int n1, int n2, int &d1, int &d2, int &dist, int level){
    if(root == NULL){
        return NULL;
    }
    if(root->data == n1){
        d1 = level;
        return root;
    }
    if(root->data == n2){
        d2 = level;
        return root;
    }

    Node* l = findDistanceUtil(root->left, n1, n2, d1, d2, dist, level+1);
    Node* r = findDistanceUtil(root->right, n1, n2, d1, d2, dist, level+1);

    if(l != NULL && r != NULL){
        dist = d1 + d2 - 2*level;
        return root;
    }

    if(l == NULL && r == NULL){
        return NULL;
    }

    return (l != NULL ? l : r);
}

int findDistance(Node* root, int n1, int n2){
    int d1 = -1, d2 = -1, dist = -1;
    Node* lca = findDistanceUtil(root, n1, n2, d1, d2, dist, 1);

    if(d1 != -1 && d2 != -1){
        return dist;
    }

    if(d1 != -1){
        dist = findLevel(lca, n2, 0); 
        return dist;
    }

    if(d2 != -1){
        dist = findLevel(lca, n1, 0); 
        return dist;
    }

    return -1;
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
    cout << "nDist(4, 6) = " << findDistance(root, 4, 6) <<endl; 
    cout << "nDist(3, 4) = " << findDistance(root, 3, 4) <<endl; 
    cout << "nDist(2, 4) = " << findDistance(root, 2, 4) <<endl; 
    cout << "nDist(8, 5) = " << findDistance(root, 8, 5) <<endl;

    return 0;
}