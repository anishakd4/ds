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

void printLevelOrderLineByLine(Node *root){
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        int nodeCount = q.size();

        for(int i=0; i<nodeCount; i++){
            Node* temp = q.front();

            cout<<temp->data<<" ";
            q.pop();

            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
        cout<<endl;
    }
}

int main(){

    Node *root = newNode(1);  
    root->left = newNode(2);  
    root->right = newNode(3);  
    root->left->left = newNode(4);  
    root->left->right = newNode(5);  
    root->right->right = newNode(6);  

    printLevelOrderLineByLine(root);
    return 0;
}