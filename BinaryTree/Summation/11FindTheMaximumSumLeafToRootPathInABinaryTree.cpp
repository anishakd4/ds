#include<iostream>

using namespace std;

class Node{
    public:
        int data;
        Node *left, *right;
};

Node* newNode(int data){
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

bool printPath(Node* root, Node* leafNode){
    if(root == NULL){
        return false;
    }

    if(root == leafNode || printPath(root->left, leafNode) || printPath(root->right, leafNode)){
        cout<<root->data<<" ";
        return true;
    }

    return false;
}

void getLeafPath(Node* root, int &maxSoFar, int curr_sum, Node* &leafNode){
    if(root == NULL){
        return;
    }

    curr_sum = curr_sum + root->data;

    if(isLeaf(root) && maxSoFar < curr_sum){
        maxSoFar = curr_sum;
        leafNode = root;
    }

    getLeafPath(root->left, maxSoFar, curr_sum, leafNode);
    getLeafPath(root->right, maxSoFar, curr_sum, leafNode);
}

int maxSumPath(Node* root){
    if(root == NULL){
        return 0;
    }
    int max_so_far = 0;
    Node* leafNode;

    getLeafPath(root, max_so_far, 0, leafNode);

    printPath(root, leafNode);

    return max_so_far;
}

int main(){

    Node* root = NULL; 
    root = newNode(10); 
    root->left = newNode(-2); 
    root->right = newNode(7); 
    root->left->left = newNode(8); 
    root->left->right = newNode(-4); 
  
    cout << "Following are the nodes on the maximum sum path \n"; 
    int sum = maxSumPath(root);
    cout<<endl;

    cout << "Sum of the nodes is " << sum <<endl; 
    return 0;
}