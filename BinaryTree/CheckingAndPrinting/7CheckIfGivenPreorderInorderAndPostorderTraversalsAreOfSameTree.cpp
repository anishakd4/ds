#include<iostream>
#include<unordered_map>

using namespace std;

struct Node{
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int data){
    struct Node* new_node = new Node;
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return new_node;
}

Node* buildTreeUtil(int inorder[], int preorder[], unordered_map<int, int> map, int &preIndex, int start, int end, int len){
    if(start > end || preIndex >= len){
        return NULL;
    }

    Node *node = newNode(preorder[preIndex]);
    preIndex++;

    if(start == end){
        return node;
    }

    int iIndex = map[node->data];

    node->left = buildTreeUtil(inorder, preorder, map, preIndex, start, iIndex-1, len);
    node->left = buildTreeUtil(inorder, preorder, map, preIndex, iIndex+1, end, len);

    return node;
}

Node* buildTree(int inorder[], int preorder[], int len){
    int preIndex = 0;

    unordered_map<int, int> map;
    for(int i=0; i< len; i++){
        map[inorder[i]] = i;
    }

    return buildTreeUtil(inorder, preorder, map, preIndex, 0, len - 1, len); 
}

void checkPostorderUtil(Node* root, int postorder[], int &index, bool &res){
    checkPostorderUtil(root->left, postorder, index, res);
    checkPostorderUtil(root->right, postorder, index, res);

    if(root->data == postorder[index]){
        index++;
    }else{
        res = false;
    }
}

bool checkPostorder(Node* root, int postorder[]){
    bool res = true;
    int index = 0;

    checkPostorderUtil(root->left, postorder, index, res);

    return res;
}

int main(){

    int inOrder[] = {4, 2, 5, 1, 3}; 
    int preOrder[] = {1, 2, 4, 5, 3}; 
    int postOrder[] = {4, 5, 2, 3, 1}; 
  
    int len = sizeof(inOrder)/sizeof(inOrder[0]); 
   
    Node* root= buildTree(inOrder, preOrder, len);
   
    if (checkPostorder(root, postOrder)) {
        cout << "Yes"; 
    }else{
        cout << "No"; 
    }

    return 0;
}