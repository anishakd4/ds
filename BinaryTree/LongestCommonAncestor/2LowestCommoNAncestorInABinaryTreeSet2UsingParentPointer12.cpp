#include<iostream>

using namespace std;

struct Node{
    int data;
    Node *left, *right, *parent;
};

Node* newNode(int data){
    Node* new_node = new Node;
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return new_node;
}

int depth(Node* node){
    int d = -1;
    while(node != NULL){
        d++;
        node = node->parent;
    }
    return d;
}

Node* insert(Node* node, int data){
    if(node == NULL){
        return newNode(data);
    }

    if(data < node->data){
        node->left = insert(node->left, data);
        node->left->parent = node;
    }

    if(data > node->data){
        node->right = insert(node->right, data);
        node->right->parent = node;
    }
    
    return node;
}

Node* LCA(Node* n1, Node* n2){
    int d1 = depth(n1);
    int d2 = depth(n2);

    if(d1 > d2){
        while(d1 > d2){
            n1 = n1->parent;
            d1--;
        }
    }else if(d2 > d1){
        while(d2 > d1){
            n2 = n2->parent;
            d2--;
        }
    }

    while(n1 != NULL && n2 != NULL){
        if(n1 == n2){
            return n1;
        }
        n1 = n1->parent;
        n2 = n2->parent;
    }

    return NULL;
}

int main(){

    Node * root = NULL; 
  
    root = insert(root, 20); 
    root = insert(root, 8); 
    root = insert(root, 22); 
    root = insert(root, 4); 
    root = insert(root, 12); 
    root = insert(root, 10); 
    root = insert(root, 14); 
  
    Node *n1 = root->left->right->left; 
    Node *n2 = root->right; 
  
    Node *lca = LCA(n1, n2); 
    printf("LCA of %d and %d is %d \n", n1->data, n2->data, lca->data); 

    return 0;
}