#include<iostream>

using namespace std;

struct Node{
    int data;
    Node *left, *right;
};

Node* newNode(int data){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return new_node;
}

void preOrder(Node* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

Node* buildTreeUtil(int in[], int post[], int &index, int start, int end, int size){
    if(start>end || index >= size || index < 0){
        return NULL;
    }

    Node* root = newNode(post[index]);
    index--;

    if(start == end){
        return root;
    }

    int i=-1;
    for(i=start; i<=end; i++){
        if(in[i] == root->data){
            break;
        }
    }

    if(i != -1 && i<=end){
        root->right = buildTreeUtil(in, post, index, i+1, end, size);
        root->left = buildTreeUtil(in, post, index, start, i-1, size);
    }

    return root;
}

Node* buildTree(int in[], int post[], int size){
    int index = size-1;
    return buildTreeUtil(in, post, index, 0, size-1, size);
}

int main(){

    int in[] = { 4, 8, 2, 5, 1, 6, 3, 7 }; 
    int post[] = { 8, 4, 5, 2, 6, 7, 3, 1 }; 
    int n = sizeof(in) / sizeof(in[0]); 
  
    Node* root = buildTree(in, post, n); 
  
    cout << "Preorder of the constructed tree : \n"; 
    preOrder(root); 
    cout<<endl;
  
    return 0; 
}