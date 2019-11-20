#include<iostream>
#include<vector>

#define N 6

using namespace std;

struct Node{
    int data;
    Node *left, *right;
};

struct Node* newNode(int data){
    struct Node* new_node = new Node;
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return new_node;
}

int ancestorMatrixUtil(Node *root, int mat[N][N], vector<int> anc){
    if(root == NULL){
        return 0;
    }

    int data = root->data;

    for(int i=0; i<anc.size(); i++){
        mat[anc[i]][data] = 1;
    }
    anc.push_back(data);

    int l = ancestorMatrixUtil(root->left, mat, anc); 
    int r = ancestorMatrixUtil(root->right, mat, anc);

    return l+r+1;
}

void ancestorMatrix(Node *root){
    int mat[N][N];
    vector<int> anc;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            mat[i][j] = 0;
        }
    }

    ancestorMatrixUtil(root, mat, anc);

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

int main(){

    Node *root        = newNode(5); 
    root->left        = newNode(1); 
    root->right       = newNode(2); 
    root->left->left  = newNode(0); 
    root->left->right = newNode(4); 
    root->right->left = newNode(3); 
  
    ancestorMatrix(root);
    cout<<endl;

    return 0;
}