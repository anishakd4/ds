#include<iostream>
#include<queue>

using namespace std;

struct Node{
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int data){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return new_node;
}

void mirror(Node* root){
    if(root == NULL){
        return;
    }

    queue<Node *> q;
    q.push(root);

    while(!q.empty()){
        struct Node* curr = q.front();
        q.pop();

        struct Node* temp;
        temp = curr->left;
        curr->left=curr->right;
        curr->right = temp;

        if(curr->left){
            q.push(curr->left);
        }
        if(curr->right){
            q.push(curr->right);
        }
    }
}

void inorder(Node* root){
    if(root != NULL){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

int main(){

    struct Node *root = newNode(1); 
    root->left        = newNode(2); 
    root->right       = newNode(3); 
    root->left->left  = newNode(4); 
    root->left->right = newNode(5); 
  
    cout << "Inorder traversal of the constructed tree is: "<<endl; 
    inorder(root); 
    cout<<endl;
  
    mirror(root); 
  
    cout << "Inorder traversal of the mirror tree is: "<<endl; 
    inorder(root); 
    cout<<endl;

    return 0;
}