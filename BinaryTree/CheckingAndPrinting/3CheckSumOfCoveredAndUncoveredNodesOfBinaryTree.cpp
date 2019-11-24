#include<iostream>

using namespace std;

struct Node{
    int data;
    Node *left, *right;
};

struct Node* newNode(int data){
    struct Node*  new_node = new Node;
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return new_node;
}

void leftSumUtil(Node *node, int &sum){
    if(node->left){
        leftSumUtil(node->left, sum);
    }else if(node->right){
        leftSumUtil(node->right, sum);
    }

    sum = sum + node->data;
}

int leftSum(Node *root){
    int sum = 0;
    leftSumUtil(root, sum);

    return sum;
}

void rightSumUtil(Node *node, int &sum){
    if(node->right){
        leftSumUtil(node->right, sum);
    }else if(node->left){
        leftSumUtil(node->left, sum);
    }

    sum = sum + node->data;
}

int rightSum(Node *root){
    int sum = 0;
    rightSumUtil(root, sum);

    return sum;
}

void totalSumUtil(Node *root, int &sum){
    if(root != NULL){
        totalSumUtil(root->left, sum);
        totalSumUtil(root->right, sum);
        sum = sum + root->data;
    }
}

int totalSum(Node *root){
    int sum=0;
    totalSumUtil(root, sum);

    return sum;
}

bool isSumSame(Node *root){
    int uncovered = leftSum(root) + rightSum(root);
    int covered = totalSum(root) - uncovered;

    return (uncovered == covered);
}

int main(){

    Node* root = newNode(8); 
    root->left = newNode(3); 
  
    root->left->left = newNode(1); 
    root->left->right = newNode(6); 
    root->left->right->left = newNode(4); 
    root->left->right->right = newNode(7); 
  
    root->right = newNode(10); 
    root->right->right = newNode(14); 
    root->right->right->left = newNode(13); 

    if (isSumSame(root)) 
        printf("Sum of covered and uncovered is same\n"); 
    else
        printf("Sum of covered and uncovered is not same\n"); 

    cout<<endl;

    return 0;
}