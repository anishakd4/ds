#include<iostream>
#include<queue>

using namespace std;

struct Node{
    int data;
    Node *left, *right;
};

struct Node* newNode(int data){
    struct Node* new_node = new Node;
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return new_node;
}

void printLevelOrder(Node* root){
    queue<Node *> q;

    q.push(root);

    while(!q.empty()){

        int nodeCount = q.size();

        while(nodeCount > 0){
            nodeCount--;

            Node *temp = q.front();
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

    cout<<endl;
}

Node* flipBinaryTree(Node* root){
    if (root == NULL) {
        return root;
    } 
    if (root->left == NULL && root->right == NULL) {
        return root;
    }

    Node* flippedRoot = flipBinaryTree(root->left);

    if(root->left != NULL){
        root->left->left = root->right;
        root->left->right = root;
        root->left = NULL;
        root->right = NULL;
    }
    return flippedRoot;
}

int main(){

    Node* root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->right->left = newNode(4); 
    root->right->right = newNode(5); 
  
    cout << "Level order traversal of given tree\n"; 
    printLevelOrder(root); 
    cout<<endl;
  
    root = flipBinaryTree(root); 
  
    cout << "\nLevel order traversal of the flipped tree\n"; 
    printLevelOrder(root);
    cout<<endl;

    return 0;
}