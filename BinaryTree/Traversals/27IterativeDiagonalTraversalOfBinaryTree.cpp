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

void diagonalPrint(Node *root){

    if (root == NULL) {
        return;
    }

    queue<Node *> q;
    q.push(root);

    while(!q.empty()){
        int sz = q.size();
        for(int i=0; i<sz; i++){
            Node *temp = q.front();
            q.pop();

            if(temp){
                while(temp){
                    cout<<temp->data<<" ";
                    if(temp->left){
                        q.push(temp->left);
                    }
                    temp = temp->right;
                }
            }
        }
        
        cout<<endl;
    }
}

int main(){

    Node* root = newNode(8); 
    root->left = newNode(3); 
    root->right = newNode(10); 
    root->left->left = newNode(1); 
    root->left->right = newNode(6); 
    root->right->right = newNode(14); 
    root->right->right->left = newNode(13); 
    root->left->right->left = newNode(4); 
    root->left->right->right = newNode(7); 

    diagonalPrint(root); 
    cout<<endl;

    return 0;
}