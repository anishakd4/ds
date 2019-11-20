#include<iostream>

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

void printInOrder(Node* node){
    if(node == NULL){
        return;
    }
    printInOrder(node->left);
    cout<<node->data<<" ";
    printInOrder(node->right);
}

Node* constructBinaryTreeUtil(int pre[], int preMirror[], int &preIndex, int start, int end, int size){
    if(preIndex >= size || start > end){
        return NULL;
    }

    Node* root = newNode(pre[preIndex]);
    preIndex++;

    if(start == end){
        return root;
    }

    int i=-1;
    for(i=start; i<=end; i++){
        if(pre[preIndex] == preMirror[i]){
            break;
        }
    }

    if(i !=-1 && i<= end){
        root->left = constructBinaryTreeUtil(pre, preMirror, preIndex, i, end, size);
        root->right = constructBinaryTreeUtil(pre, preMirror, preIndex, start+1, i-1, size);
    }

    return root;
}

Node* constructBinaryTree(int pre[], int preMirror[], int size){
    int preIndex = 0;

    return constructBinaryTreeUtil(pre, preMirror, preIndex, 0, size-1, size);
}

int main(){

    int preOrder[] = {1,2,4,5,3,6,7}; 
    int preOrderMirror[] = {1,3,7,6,2,5,4};

    int size = sizeof(preOrder)/sizeof(preOrder[0]);

    Node * root = constructBinaryTree(preOrder, preOrderMirror, size);

    printInOrder(root);
    cout<<endl;

    return 0;
}