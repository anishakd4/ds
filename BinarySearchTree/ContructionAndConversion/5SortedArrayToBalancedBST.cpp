#include<iostream>

using namespace std;

class TNode{
    public:
        int data;
        TNode *left, *right;
};

TNode* newNode(int data){
    TNode* new_node = new TNode();
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return new_node;
}

void preOrder(TNode* node){
    if(node == NULL){
        return;
    }
    cout<<node->data<<" ";
    preOrder(node->left);
    preOrder(node->right);
}

TNode* sortedArrayToBSTUtil(int arr[], int l, int r){
    if(l > r){
        return NULL;
    }

    if(l == r){
        return newNode(arr[l]);
    }

    int mid = (l+r)/2;

    TNode* root = newNode(arr[mid]);
    root->left = sortedArrayToBSTUtil(arr, l, mid-1);
    root->right = sortedArrayToBSTUtil(arr, mid+1, r);

    return root;

}

TNode* sortedArrayToBST(int arr[], int n){
    return sortedArrayToBSTUtil(arr, 0, n-1);
}

int main(){

    int arr[] = {1, 2, 3, 4, 5, 6, 7};  
    int n = sizeof(arr) / sizeof(arr[0]);  
  
    TNode *root = sortedArrayToBST(arr, n);  

    cout << "PreOrder Traversal of constructed BST \n";  
    preOrder(root); 
    cout<<endl;

    return 0;
}