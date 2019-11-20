#include<iostream>

using namespace std;

class Node{
    public:
        int data;
        Node *left, *right;
};

Node* newNode(int data){
    Node* new_node = new Node();
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return new_node;
}

void printInorder(Node* root){
    if(root == NULL){
        return;
    }
    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}

int maxInt(int arr[], int start, int end){
    int maxi = arr[start];
    int maxIndex = start;
    for(int i=start+1; i<=end; i++){
        if(maxi < arr[i]){
            maxi = arr[i];
            maxIndex = i;
        }
    }
    return maxIndex;
}

Node* buildTreeUtil(int inorder[], int start, int end){

    if(start>end){
        return NULL;
    }

    int maxIndex = maxInt(inorder, start, end);

    Node *root = newNode(inorder[maxIndex]);

    if(start == end){
        return root;
    }

    root->left = buildTreeUtil(inorder, start, maxIndex-1);
    root->right = buildTreeUtil(inorder, maxIndex+1, end);

    return root;
}

Node* buildTree(int inorder[], int size){
    return buildTreeUtil(inorder, 0, size - 1);
}

int main(){

    int inorder[] = {5, 10, 40, 30, 28};  
    int len = sizeof(inorder)/sizeof(inorder[0]);  

    Node *root = buildTree(inorder, len);  
  
    cout << "Inorder traversal of the constructed tree is: "<<endl;  
    printInorder(root);
    cout<<endl;

    return 0;
}