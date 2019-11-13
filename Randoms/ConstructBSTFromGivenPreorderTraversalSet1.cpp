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

void printInorder(Node *root){
    if(root == NULL){
        return;
    }
    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}

Node* constructTree(int pre[], int low, int high){
    if(high < low){
        return NULL;
    }

    Node* root = NULL;
    root = newNode(pre[low]);

    if(high == low){
        return root;
    }

    int max = -1;
    for(int i=low+1; i<=high; i++){
        if(pre[i] > pre[low]){
            max = i;
            break;
        }
    }

    if(max != 0){
        root->left = constructTree(pre, low+1, max-1);
        root->right = constructTree(pre, max, high);
    }else{
        root->left = constructTree(pre, low+1, high);
    }

    return root;
}

int main(){

    int pre[] = {10, 5, 1, 7, 40, 50};
    int n = sizeof(pre)/sizeof(pre[0]);

    Node* root = constructTree(pre, 0, n-1);

    cout<<"Inorder traversal of the constructed tree: "<<endl;
    printInorder(root);
    cout<<endl;

    return 0;
}