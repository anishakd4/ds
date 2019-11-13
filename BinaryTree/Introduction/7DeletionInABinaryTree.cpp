#include<iostream>
#include<queue>

using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

struct Node* newNode(int data){
    struct Node* temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

void inorder(struct Node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void deleteDeepestNode(Node *root, Node* keyNode){
    if(root == NULL){
        return;
    }

    queue<Node *> q;
    q.push(root);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if (temp == keyNode) { 
            temp = NULL; 
            delete (keyNode); 
            return; 
        } 

        if(temp->left != NULL && temp->left == keyNode){
            temp->left = NULL;
            delete(keyNode);
            return;
        }else{
            q.push(temp->left);
        }

        if(temp->right != NULL && temp->right == keyNode){
            temp->right = NULL;
            delete(keyNode);
            return;
        }else{
            q.push(temp->right);
        }
    }

}

Node* deletion(Node* root, int key){
    if(root == NULL){
        return NULL;
    }

    if(root->left == NULL && root->right == NULL){
        if(root->data == key){
            return NULL;
        }else{
            return root;
        }
    }

    queue<Node *> q;
    q.push(root);

    struct Node* temp;
    struct Node* keyNode = NULL;
    while(!q.empty()){
        temp = q.front();
        q.pop();

        if(temp->data == key){
            keyNode = temp;
        }

        if(temp->left != NULL){
            q.push(temp->left);
        }

        if(temp->right != NULL){
            q.push(temp->right);
        }
    }

    if(keyNode != NULL){
        keyNode->data = temp->data;
        deleteDeepestNode(root, temp);
    }

    return root;
}

int main(){

    struct Node* root = newNode(10); 
    root->left = newNode(11); 
    root->left->left = newNode(7); 
    root->left->right = newNode(12); 
    root->right = newNode(9); 
    root->right->left = newNode(15); 
    root->right->right = newNode(8); 
  
    cout << "Inorder traversal before deletion : "; 
    inorder(root); 
    cout << endl; 
   
    root = deletion(root, 11); 
    
    cout << "Inorder traversal after deletion : "; 
    inorder(root); 
    cout << endl; 

    return 0;
}