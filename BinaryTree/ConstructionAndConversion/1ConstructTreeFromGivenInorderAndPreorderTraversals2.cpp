#include<iostream>
#include<unordered_map>

using namespace std;

struct Node{
    char data;
    struct Node *left, *right;
};

struct Node* newNode(char data){
    struct Node* new_node = new Node;
    new_node->data = data;
    new_node->left =  new_node->right = NULL;
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

struct Node* buildTree(char in[], char pre[], int start, int end, unordered_map<char, int> map){
    static int preIndex = 0;

    if(start > end){
        return NULL;
    }

    struct Node* node = newNode(pre[preIndex]);
    preIndex++;

    if(start == end){
        return node;
    }

    int inIndex = map[node->data];

    node->left = buildTree(in, pre, start, inIndex-1, map);
    node->right = buildTree(in, pre, inIndex+1, end, map);

    return node;
}

struct Node* buldTreeWrap(char in[], char pre[], int len){
    unordered_map<char, int> map;
    for(int i=0; i<len; i++){
        map[in[i]] = i;
    }

    return buildTree(in, pre, 0, len - 1, map); 
}

int main(){

    char in[] = { 'D', 'B', 'E', 'A', 'F', 'C' }; 
    char pre[] = { 'A', 'B', 'D', 'E', 'C', 'F' }; 
    int len = sizeof(in) / sizeof(in[0]); 
  
    struct Node* root = buldTreeWrap(in, pre, len); 
  
    printf("Inorder traversal of the constructed tree is \n"); 
    printInorder(root);
    cout<<endl;

    return 0;
}