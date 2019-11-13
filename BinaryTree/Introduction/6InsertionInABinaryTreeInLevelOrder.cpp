#include<iostream>
#include<queue>

using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

struct Node* newNode(int data){
    struct Node* new_node = new Node;
    new_node->data=data;
    new_node->left = new_node->right = NULL;
    return new_node;
}

void inorder(Node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void insert(struct Node* root, int data){
    queue<Node *> q;
    q.push(root);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if(temp->left == NULL){
            temp->left = newNode(data);
            break;
        }else{
            q.push(temp->left);
        }

        if(temp->right == NULL){
            temp->right = newNode(data);
            break;
        }else{
            q.push(temp->right);
        }
    }
}

int main(){
    struct Node* root = newNode(10); 
    root->left = newNode(11); 
    root->left->left = newNode(7); 
    root->right = newNode(9); 
    root->right->left = newNode(15); 
    root->right->right = newNode(8);

    cout << "Inorder traversal before insertion:"<<endl;
    inorder(root);
    cout<<endl;

    insert(root, 12);

    cout << "Inorder traversal after insertion:"<<endl; 
    inorder(root);
    cout<<endl;

    return 0;
}