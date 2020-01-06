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

bool findNode(Node* root, int k){
    if(root == NULL){
        return false;
    }

    if(root->data == k){
        return true;
    }

    return ((findNode(root->left, k)) && (findNode(root->right, k)));
}

bool printCommonNodes(Node* root, Node* lca){
    if(root == NULL){
        return false;
    }

    if(root == lca){
        cout<<root->data<<" ";
        return true;
    }

    if(printCommonNodes(root->left, lca) == true || printCommonNodes(root->right, lca) == true){
        cout<<root->data<<" ";
        return true;
    }

    return false;

}

Node* findLca(Node* root, int n1, int n2, bool &v1, bool &v2){
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

    Node* l = findLca(root->left, n1, n2, v1, v2);
    Node* r = findLca(root->right, n1, n2, v1, v2);

    if(l != NULL && r != NULL){
        return root;
    }

    if(l == NULL && r == NULL){
        return NULL;
    }

    return (l != NULL ? l : r);
}

void findCommonNodes(Node* root, int n1, int n2){
    bool v1=false, v2=false;
    Node* lca = findLca(root, n1, n2, v1, v2);

    if(v1 == true && v2 == true){
        printCommonNodes(root, lca);
        return;
    }

    if(v1 == true){
        if(findNode(lca, v2)){
            printCommonNodes(root, lca);
            return;
        }else{
            return;
        }
    }

    if(v2 == true){
        if(findNode(lca, v1)){
            printCommonNodes(root, lca);
            return;
        }else{
            return;
        }
    }
}

int main(){

    Node* root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left = newNode(6); 
    root->right->right = newNode(7); 
    root->left->left->left = newNode(8); 
    root->right->left->left = newNode(9); 
    root->right->left->right = newNode(10); 
  
    findCommonNodes(root, 9, 7);

    return 0;
}