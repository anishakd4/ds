#include<iostream>
#include<queue>

using namespace std;

struct Node{
    int data;
    Node *left, *right;
};

Node* getNode(int data){
    Node* new_node = new Node;
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return new_node;
}

bool isLeaf(Node* node){
    if(node != NULL && node->left == NULL && node->right == NULL){
        return true;
    }
    return false;
}

int sumOfLeafNodesAtMinLevel(Node* node){
    if(node == NULL){
        return 0;
    }

    queue<Node*> q;
    q.push(node);

    int sum = 0;
    bool flag = false;

    while(!q.empty()){

        int nodeCount = q.size();
        sum=0;

        for(int i=0; i<nodeCount; i++){
            Node* temp = q.front();
            q.pop();

            if(isLeaf(temp)){
                flag = true;
                sum = sum + temp->data;
            }

            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }

        if(flag){
            break;
        }
    }

    return sum;
}

int main(){

    Node* root = getNode(1); 
    root->left = getNode(2); 
    root->right = getNode(3); 
    root->left->left = getNode(4); 
    root->left->right = getNode(5); 
    root->right->left = getNode(6); 
    root->right->right = getNode(7); 
    root->left->right->left = getNode(8); 
    root->right->left->right = getNode(9); 
  
    cout << "Sum = "<< sumOfLeafNodesAtMinLevel(root)<<endl; 

    return 0;
}