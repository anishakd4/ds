#include<iostream>
#include<queue>

using namespace std;

struct Node{
    int data;
    Node *left, *right;
};

Node* newNode(int data){
    Node* new_node = new Node;
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return new_node;
}

int evenOddLevelDifference(Node* node){
    if(node == NULL){
        return 0;
    }
    queue<Node *>q;
    q.push(node);

    int evenSum = 0, oddSum = 0;

    bool level = true;

    while(!q.empty()){
        int nodeCount = q.size();

        for(int i=0; i<nodeCount; i++){
            Node* temp = q.front();
            q.pop();
            if(level){
                oddSum = oddSum + temp->data;
            }else{
                evenSum = evenSum + temp->data;
            }

            if(temp->left){
                q.push(temp->left);
            }

            if(temp->right){
                q.push(temp->right);
            }
        }

        level = !level;
    }

    return oddSum - evenSum;
}

int main(){

    Node* root = newNode(5); 
    root->left = newNode(2); 
    root->right = newNode(6); 
    root->left->left = newNode(1); 
    root->left->right = newNode(4); 
    root->left->right->left = newNode(3); 
    root->right->right = newNode(8); 
    root->right->right->right = newNode(9); 
    root->right->right->left = newNode(7); 
  
    int result = evenOddLevelDifference(root); 
    cout << "diffence between sums is :: "; 
    cout << result << endl; 

    return 0;
}