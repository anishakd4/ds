#include<iostream>

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

void sumOfNodesAtMaxDepth(Node* root, int &sum, int &max_level, int curr_level){
    if(root == NULL){
        return;
    }

    if(curr_level > max_level){
        max_level = curr_level;
        sum = root->data;
    }else if(curr_level == max_level){
        sum = sum + root->data;
    }

    sumOfNodesAtMaxDepth(root->l, sum, max_level, curr_level + 1);
    sumOfNodesAtMaxDepth(root->r, sum, max_level, curr_level + 1);
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

    int sum = 0;
    int max_level = -1;
    sumOfNodesAtMaxDepth(root, sum, max_level, 0); 
    cout << sum << endl; 

    return 0;
}