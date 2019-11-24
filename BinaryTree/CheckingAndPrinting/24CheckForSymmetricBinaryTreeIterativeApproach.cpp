#include<iostream>
#include<queue>

using namespace std;

struct Node{
    int data;
    Node *left, *right;
};

struct Node* newNode(int data){
    Node* new_node = new Node;
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return new_node;
}

bool isSymmetric(Node* root){
    if(root == NULL){
        return true;
    }

    if(root->left == NULL && root->right == NULL){
        return true;
    }

    queue<Node*> q;

    q.push(root);
    q.push(root);

    Node *leftNode, *rightNode;
    while(!q.empty()){
        leftNode = q.front();
        q.pop();
        rightNode = q.front();
        q.pop();

        if(leftNode->data != rightNode->data){
            return false;
        }

        if(leftNode->left && rightNode->right){
            q.push(leftNode->left);
            q.push(rightNode->right);
        }else if(leftNode->left == NULL && rightNode->right != NULL){
            return false;
        }else if(leftNode->left != NULL && rightNode->right == NULL){
            return false;
        }

        if(leftNode->right && rightNode->left){
            q.push(leftNode->right);
            q.push(rightNode->left);
        }else if(leftNode->right == NULL && rightNode->left != NULL){
            return false;
        }else if(leftNode->right != NULL && rightNode->left == NULL){
            return false;
        }
    }

    return true;
}

int main(){

    return 0;
}