#include<iostream>

using namespace std;

struct Node{
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int data){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return new_node;
}

void printInorder(Node* node) {
    if (node == NULL) {
        return;
    } 
    printInorder(node->left); 
    cout << node->data << " "; 
    printInorder(node->right); 
} 

int search(int arr[], int strt, int end, int value) { 
    for (int i = strt; i <= end; i++) {
        if (arr[i] == value){
            return i; 
        } 
    }  
    return -1; 
}

int *extrackKeys(int in[], int level[], int m, int n) {
    int *newlevel = new int[m], j = 0; 
    for (int i = 0; i < n; i++) {
        if (search(in, 0, m-1, level[i]) != -1) {
            newlevel[j] = level[i], 
            j++; 
        }
    }
    return newlevel; 
} 

Node* buildTree(int in[], int level[], int start, int end, int n){
    if(start > end){
        return NULL;
    }

    Node *root = newNode(level[0]);

    if (start == end) {
        return root; 
    }

    int inIndex = search(in, start, end, root->data);

    int *llevel  = extrackKeys(in, level, inIndex, n); 
    int *rlevel  = extrackKeys(in + inIndex + 1, level, n-inIndex-1, n); 
  
    root->left = buildTree(in, llevel, start, inIndex-1, n); 
    root->right = buildTree(in, rlevel, inIndex+1, end, n); 
  
    delete [] llevel; 
    delete [] rlevel;

    return root;
}

int main(){

    int in[]    = {4, 8, 10, 12, 14, 20, 22}; 
    int level[] = {20, 8, 22, 4, 12, 10, 14};

    int n = sizeof(in)/sizeof(in[0]);

    Node *root = buildTree(in, level, 0, n - 1, n); 
  
    cout << "Inorder traversal of the constructed tree is \n"; 
    printInorder(root); 
    cout<<endl;

    return 0;
}