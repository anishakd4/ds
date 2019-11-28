#include<iostream>
#include<queue>

using namespace std;

struct Node{
    int data;
    Node *l, *r;
};

Node* createNode(int data){
    Node* new_node = new Node;
    new_node->data = data;
    new_node->l = new_node->r = NULL;
    return new_node;
}

int sumOfNodesAtMaxDepth(Node* root){
    if(root == NULL){
        return 0;
    }

    queue<Node*> q;
    q.push(root);

    int sum = 0;

    while(!q.empty()){
        int nodeCount = q.size();

        sum = 0;

        for(int i=0; i<nodeCount; i++){
            Node* temp = q.front();
            q.pop();

            sum = sum + temp->data;

            if(temp->l){
                q.push(temp->l);
            }

            if(temp->r){
                q.push(temp->r);
            }
        }
    }
    
    return sum;
}

int main(){

    Node *root; 
    root = createNode(1); 
    root->l = createNode(2); 
    root->r = createNode(3); 
    root->l->l = createNode(4); 
    root->l->r = createNode(5); 
    root->r->l = createNode(6); 
    root->r->r = createNode(7); 

    
    cout << sumOfNodesAtMaxDepth(root) << endl; 

    return 0;
}