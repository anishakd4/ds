#include<iostream>

using namespace std;

struct Node{
    int data;
    Node *next, *child;
};

struct Node* newNode(int data){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = new_node->child = NULL;
    return new_node;
}

Node* addSibling(Node *node, int data){
    if(node == NULL){
        return NULL;
    }
    while(node->next){
        node = node->next;
    }
    return (node->next = newNode(data));
}

Node* addChild(Node *root, int data){
    if(root == NULL){
        return NULL;
    }
    if(root->child){
        return addSibling(root->child, data);
    }else{
        return (root->child = newNode(data));
    }
}

void traverseTree(Node* root){
    if(root == NULL){
        return;
    }

    while(root){
        cout<<root->data<<" ";
        if(root->child){
            traverseTree(root->child);
        }
        root = root->next;
    }
}

int main(){

    Node *root = newNode(10); 
    Node *n1  = addChild(root, 2); 
    Node *n2  = addChild(root, 3); 
    Node *n3  = addChild(root, 4); 
    Node *n4  = addChild(n3, 6); 
    Node *n5  = addChild(root, 5); 
    Node *n6  = addChild(n5, 7); 
    Node *n7  = addChild(n5, 8); 
    Node *n8  = addChild(n5, 9); 

    traverseTree(root); 
    cout<<endl;

    return 0;
}