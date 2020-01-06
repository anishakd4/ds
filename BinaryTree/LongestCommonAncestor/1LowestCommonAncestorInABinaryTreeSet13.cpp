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

bool find(Node* node, int k){
    if(node == NULL){
        return false;
    }

    if(node->data == k){
        return true;
    }

    if(find(node->left, k) || find(node->right, k)){
        return true;
    }

    return false;
}

Node* findLcaUtil(Node* root, int n1, int n2, bool &v1, bool &v2){
    if(root == NULL){
        return NULL;
    }

    if(root->data == n1){
        v1 = true;
        return root;
    }
    if(root->data == n2){
        v2 = true;
        return root;
    }

    Node* l = findLcaUtil(root->left, n1, n2, v1, v2);
    Node* r = findLcaUtil(root->right, n1, n2, v1, v2);

    if (l && r){
        return root;
    } 
    if( l == NULL && r == NULL){
        return NULL;
    }
    return (l != NULL)? l: r;
}

Node* findLCA(Node* root, int n1, int n2){
    bool v1 = false, v2 = false;

    Node *lca = findLcaUtil(root, n1, n2, v1, v2);

    if((v1 && v2) && (v1 && find(lca, n2)) && (v2 && find(lca, n1))){
        return lca;
    }

    return NULL;
}

int main(){

    Node * root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left = newNode(6); 
    root->right->right = newNode(7); 

    Node *lca =  findLCA(root, 4, 5); 
    if (lca != NULL) 
       cout << "LCA(4, 5) = " << lca->data; 
    else
       cout << "Keys are not present "; 

    cout<<endl;
  
    lca =  findLCA(root, 4, 10); 

    if (lca != NULL) 
       cout << "nLCA(4, 10) = " << lca->data; 
    else
       cout << "nKeys are not present "; 
    
    cout<<endl;

    return 0;
}