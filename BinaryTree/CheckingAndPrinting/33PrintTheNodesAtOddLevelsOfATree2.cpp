#include<iostream>
#include<queue>

using namespace std;

struct Node{
    int data;
    Node *left, *right;
};

Node* newNode(int data){
    Node* new_node = new Node;
    new_node->right = new_node->left = NULL;
    new_node->data = data;
    return new_node;
}

void printOddNodes(Node* root){
    if(root == NULL){
        return;
    }
    queue<Node *> q;
    q.push(root);

    bool isOdd = true;

    while(1){
        int count = q.size();
        if (count == 0) {
            break;
        }

        for(int i=count-1; i>=0; i--){
            Node* temp = q.front();
            q.pop();

            if(isOdd){
                cout<<temp->data<<" ";
            }

            if(temp->left){
                q.push(temp->left);
            }

            if(temp->right){
                q.push(temp->right);
            }
        }
        isOdd = !isOdd;
    }
}

int main(){

    struct Node* root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 

    printOddNodes(root);
    cout<<endl;

    return 0;
}