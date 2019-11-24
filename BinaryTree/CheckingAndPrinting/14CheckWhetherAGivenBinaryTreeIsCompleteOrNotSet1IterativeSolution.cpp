#include<iostream>
#include<queue>

using namespace std;

class Node{
    public:
        int data;
        Node *left, *right;
};

Node* newNode(int data){
    struct Node* new_node = new Node();
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return new_node;
}

bool firstNonFullNode(Node *root){
    if(root->left == NULL && root->right != NULL){
        return true;
    }else if(root->left == NULL && root->right == NULL){
        return true;
    }

    return false;
}

bool isCompleteBT(Node* root){
    queue<Node *> q;
    q.push(root);

    bool flag = true;

    while(q.empty()){
        Node *temp = q.front();
        q.pop();

        if(temp->left == NULL && temp->right != NULL){
            return false;
        }

        if(flag == false){
            if(temp->left != NULL || temp->right != NULL){
                return false;
            }
        }

        if(firstNonFullNode(temp)){
            flag = false;
        }

        if(temp->left){
            q.push(temp->left);
        }

        if(temp->right){
            q.push(temp->right);
        }
    }

    return true;
}

int main(){

    Node* root = newNode(1);  
    root->left     = newNode(2);  
    root->right = newNode(3);  
    root->left->left = newNode(4);  
    root->left->right = newNode(5);  
    root->right->right = newNode(6);  
      
    if ( isCompleteBT(root) == true )  
        cout << "Complete Binary Tree";  
    else
        cout << "NOT Complete Binary Tree";  
      
    cout<<endl;

    return 0;
}