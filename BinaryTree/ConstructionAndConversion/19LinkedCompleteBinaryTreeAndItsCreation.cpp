#include<iostream>
#include<queue>

using namespace std;

class Node{
    public:
        int data;
        Node *left, *right;
};

Node* newNode(int data){
    Node* new_node = new Node();
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return new_node;
}

void levelOrder(Node *root){
    queue<Node *> qu;

    qu.push(root);

    while(!qu.empty()){
        Node *temp = qu.front();
        cout<<temp->data<<" ";
        qu.pop();

        if(temp->left){
            qu.push(temp->left);
        }
        if(temp->right){
            qu.push(temp->right);
        }
    }
}

void insert(Node* &root, int data, queue<Node *> &qu){
    Node *new_node = newNode(data);

    if(root == NULL){
        root = new_node;
    }else{
        Node *temp = qu.front();

        if(!temp->left){
            temp->left = new_node;
        }else if(!temp->right){
            temp->right = new_node;
        }
        if(temp->left && temp->right){
            qu.pop();
        }
        
    }

    qu.push(new_node);
}

int main(){

    Node* root = NULL;  
    queue<Node *> qu; 
    int i;  
  
    for(i = 1; i <= 12; ++i){
        insert(root, i, qu);
    }  
  
    levelOrder(root);
    cout<<endl;

    return 0;
}