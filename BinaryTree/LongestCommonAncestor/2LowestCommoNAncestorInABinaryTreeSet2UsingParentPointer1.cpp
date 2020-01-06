#include<iostream>
#include<unordered_set>

using namespace std;

struct Node{
    Node *left, *right, *parent;
    int data;
};

Node* newNode(int data){
    Node* new_node = new Node;
    new_node->data = data;
    new_node->right = new_node->left = new_node->parent = NULL;
    return new_node;
}

Node* insert(Node* root, int data){
    if(root == NULL){
        return newNode(data);
    }

    if(data < root->data){
        root->left = insert(root->left, data);
        root->left->parent = root;
    }else if(data > root->data){
        root->right = insert(root->right, data);
        root->right->parent = root;
    }
    
    return root;
}

Node* LCA(Node* n1, Node* n2){
   unordered_set<Node*> set;

   while(n1 != NULL){
       set.insert(n1);
       n1 = n1->parent;
   }

   while(n2 != NULL){
       if(set.find(n2) != set.end()){
           return n2;
       }
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
    Node *n2 = root->left; 
    Node *lca = LCA(n1, n2); 

    printf("LCA of %d and %d is %d \n", n1->data, n2->data, lca->data); 

    return 0;
}