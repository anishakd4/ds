#include<iostream>

using namespace std;

class Node{
    public:
        int data;
        Node *left, *right;
        int height;
};

Node* newNode(int data){
    Node* new_node = new Node();
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    new_node->height = 1;
    return new_node;
}

int height(Node* node){
    if(node == NULL){
        return 0;
    }
    return node->height;
}

int getBalance(Node* node){
    if(node == NULL){
        return 0;
    }
    return (height(node->left) - height(node->right));
}

void preorder(Node *root){
    if(root != NULL){
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}

Node* leftRotate(Node *x){
    Node* a = x->right;
    Node* b = a->left;

    a->left = x;
    x->right = b;

    x->height = max(height(x->left), height(x->right)) + 1;
    a->height = max(height(a->left), height(a->right)) + 1;

    return a;
}

Node* rightRotate(Node *y){
    Node* a = y->left;
    Node* b = a->right;

    a->right = y;
    y->left = b;

    y->height = max(height(y->left), height(y->right)) + 1;
    a->height = max(height(a->left), height(a->right)) + 1;

    return a;
}

Node* insert(Node *node, int data){
    if(node == NULL){
        return newNode(data);
    }

    if(data < node->data){
        node->left = insert(node->left, data);
    }else if(data > node->data){
        node->right = insert(node->right, data);
    }else{
        return node;
    }

    int balance = getBalance(node);

    //Left Left
    if(balance > 1 && data < node->left->data){
        return rightRotate(node);
    }

    //Left right
    if (balance > 1 && data > node->left->data)  {
        node->left = leftRotate(node->left);  
        return rightRotate(node);  
    }

    //Right Right
    if(balance < -1 && data > node->right->data){
        return leftRotate(node);
    }

    // Right Left Case  
    if (balance < -1 && data < node->right->data)  {  
        node->right = rightRotate(node->right);  
        return leftRotate(node);  
    } 

    return node;
}

int main(){

    Node *root = NULL;  
    
    root = insert(root, 10);  
    root = insert(root, 20);  
    root = insert(root, 30);  
    root = insert(root, 40);  
    root = insert(root, 50);  
    root = insert(root, 25); 

    cout << "Preorder traversal of the constructed AVL tree is "<<endl;  
    preorder(root);
    cout<<endl;

    return 0;
}