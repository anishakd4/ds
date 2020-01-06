#include<iostream>
#include<vector>
#include<algorithm>

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

void printInorder(Node* root){
    if(root == NULL){
        return;
    }
    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}

void storeInorder(Node* root, vector<int> &inorderArr){
    if(root == NULL){
        return;
    }
    storeInorder(root->left, inorderArr);
    inorderArr.push_back(root->data);
    storeInorder(root->right, inorderArr);
}

void arrayToBst(Node* root, vector<int> inorderArr, int &i){
    if(root == NULL){
        return;
    }
    arrayToBst(root->left, inorderArr, i);
    root->data = inorderArr[i];
    i++;
    arrayToBst(root->right, inorderArr, i);
}

void binaryTreeToBST(Node* root){
    if(root == NULL){
        return;
    }

    vector<int> inorderArr;
    storeInorder(root, inorderArr);

    sort(inorderArr.begin(), inorderArr.end());

    int i=0;
    arrayToBst(root, inorderArr, i);
}

int main(){

    struct Node *root = NULL; 
    root = newNode(10); 
    root->left = newNode(30); 
    root->right = newNode(15); 
    root->left->left = newNode(20); 
    root->right->right = newNode(5); 
  
    binaryTreeToBST(root); 
  
    printf("Following is Inorder Traversal of the converted BST: \n"); 
    printInorder (root); 
    cout<<endl;

    return 0;
}