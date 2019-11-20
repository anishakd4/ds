#include<iostream>
#include<unordered_map>

using namespace std;

struct Node{
    int data;
    Node *left,*right;
};

Node* newNode(int data){
    Node* new_node = new Node;
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return new_node;
}

void preOrder(Node* node){
    if(node == NULL){
        return;
    }
    cout<<node->data<<" ";
    preOrder(node->left);
    preOrder(node->right);
}

Node* buildTreeUitl(int in[], int post[], int &index, int start, int end, int size, unordered_map<int, int> map){
    if(start > end || index < 0 || index >= size){
        return NULL;
    }

    Node* root = newNode(post[index]);
    index--;

    if(start == end){
        return root;
    }

    int iIndex = map[root->data];

    root->right = buildTreeUitl(in, post, index, iIndex+1, end, size, map);
    root->left = buildTreeUitl(in, post, index, start, iIndex-1, size, map);

    return root;
}

Node* buildTree(int in[], int post[], int size){
    unordered_map<int, int> map;
    for(int i=0; i<size; i++){
        map[in[i]] = i;
    }

    int index = size-1;
    return buildTreeUitl(in, post, index, 0, size-1, size, map);
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