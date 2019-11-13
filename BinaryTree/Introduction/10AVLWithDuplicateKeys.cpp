#include<iostream>

using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    int height;
    int count;
};

struct Node* newNode(int data){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    new_node->count = 1;
    new_node->height = 1;
    return new_node;
}

int height(struct Node* node){
    if(node ==  NULL){
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

void preOrder(struct Node* root){
    if(root != NULL){
        cout<<root->data<<"("<<root->count<<")"<<" ";
        preOrder(root->left); 
        preOrder(root->right); 
    }
}

struct Node* minValueNode(struct Node* node){
    while(node->left != NULL){
        node = node->left;
    }
    return node;
}

struct Node* rightRotate(struct Node* y){
    struct Node* a = y->left;
    struct Node* b = a->right;

    a->right = y;
    y->left = b;

    y->height = max(height(y->left), height(y->right))+1; 
    a->height = max(height(a->left), height(a->right))+1;

    return a;
}

struct Node* leftRotate(struct Node* x){
    struct Node* a = x->right;
    struct Node* b = a->left;

    a->left = x;
    x->right = b;

    x->height = max(height(x->left), height(x->right))+1; 
    a->height = max(height(a->left), height(a->right))+1;

    return a;
}

struct Node* insert(struct Node* node, int data){
    if(node == NULL){
        return newNode(data);
    }

    if(data == node->data){
       (node->count)++;
       return node;
    }

    if (data < node->data) {
        node->left = insert(node->left, data); 
    }
    else{
        node->right = insert(node->right, data);
    }

    node->height = max(height(node->left), height(node->right)) + 1;

    int balance = getBalance(node);

    if(balance > 1 && data < node->left->data){
        return rightRotate(node);
    }

    if(balance > 1 && data > node->left->data){
        node->left =  leftRotate(node->left);
        return rightRotate(node);
    }

    if(balance < -1 && data > node->right->data){
        return leftRotate(node);
    }

    if(balance < -1 && data < node->right->data){
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

struct Node* deleteNode(struct Node* root, int data){
    if(root == NULL){
        return root;
    }

    if(data < root->data){
        root->left = deleteNode(root->left, data);
    }else if(data > root->data){
        root->right = deleteNode(root->right, data);
    }else{
        if(root->count > 1){
            (root->count)--;
            return root;
        }
        if((root->left == NULL) || (root->right == NULL)){
            struct Node* temp = root->left ? root->left : root->right;

            if(temp == NULL){
                temp = root;
                root = NULL;
            }else{
                *root = *temp;
            }
            free(temp);
        }else{
            struct Node* temp = minValueNode(root->right);

            root->data = temp->data;
            root->count = temp->count;
            temp->count = 1;

            root->right = deleteNode(root->right, temp->data);
        }
    }

    if(root == NULL){
        return root;
    }

    root->height = max(height(root->left), height(root->right)) + 1;

    int balance = getBalance(root);

    if(balance > 1 && data < root->left->data){
        return rightRotate(root);
    }

    if(balance > 1 && data > root->left->data){
        root->left =  leftRotate(root->left);
        return rightRotate(root);
    }

    if(balance < -1 && data > root->right->data){
        return leftRotate(root);
    }

    if(balance < -1 && data < root->right->data){
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

int main(){

    struct Node* root = NULL; 
  
    root = insert(root, 9); 
    root = insert(root, 5); 
    root = insert(root, 10); 
    root = insert(root, 5); 
    root = insert(root, 9); 
    root = insert(root, 7); 
    root = insert(root, 17); 
  
    cout<<"Pre order traversal of the constructed AVL tree is :"<<endl; 
    preOrder(root); 
    cout<<endl;
  
    root = deleteNode(root, 9); 
  
    cout<<"Pre order traversal after deletion of 9 :"<<endl; 
    preOrder(root); 
    cout<<endl;

    return 0;
}