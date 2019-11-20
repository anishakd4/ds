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

void printLevelOrderLineByLine(Node* root){
    if(root == NULL){
        return;
    }
    queue<Node *> q1, q2;
    q1.push(root);

    while(!q1.empty() || !q2.empty()){

        while(!q1.empty()){
            if (q1.front()->left != NULL) { 
                q2.push(q1.front()->left); 
            }
  
            if (q1.front()->right != NULL) {
                q2.push(q1.front()->right);
            }
  
            cout << q1.front()->data << " "; 
            q1.pop(); 
        }

        cout<<endl;

        while(!q2.empty()){
            if (q2.front()->left != NULL) { 
                q1.push(q2.front()->left); 
            }
  
            if (q2.front()->right != NULL) {
                q1.push(q2.front()->right);
            }
  
            cout << q2.front()->data << " "; 
            q2.pop(); 
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