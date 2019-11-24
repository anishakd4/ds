#include<iostream>

using namespace std;

struct Node{
    int data;
    Node *left, *right;
};

Node* newNode(int data){
    struct Node* new_node = new Node;
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return new_node;
}

bool isLeaf(Node* node){
    if(node->left == NULL && node->right == NULL){
        return true;
    }
    return false;
}

// void isPerfectUtil(Node* root, int level, int &leafLevel, bool &res){
//     if(root == NULL){
//         return;
//     }
//     if(isLeaf(root)){
//         if(leafLevel == 0){
//             leafLevel = level;
//         }else{
//             if(leafLevel != level){
//                 res = false;
//             }
//         }
//     }
//     isPerfectUtil(root->left, level + 1, leafLevel, res);
//     isPerfectUtil(root->right, level + 1, leafLevel, res);
// }

// bool isPerfect(Node* root){
//     int level = 1;
//     int leafLevel = 0;
//     bool res = true;
    
//     isPerfectUtil(root, level, leafLevel, res);

//     return res;
// }

bool isPerfectUtil(Node* root, int level, int &leafLevel){
    if(root == NULL){
        return true;
    }
    if(isLeaf(root)){
        if(leafLevel == 0){
            leafLevel = level;
            return true;
        }else{
            if(leafLevel != level){
                return false;
            }
        }
    }
    return (isPerfectUtil(root->left, level + 1, leafLevel) && isPerfectUtil(root->right, level + 1, leafLevel));
}

bool isPerfect(Node* root){
    int level = 1;
    int leafLevel = 0;
    
    return isPerfectUtil(root, level, leafLevel);
}

int main(){

    struct Node* root = NULL; 
    root = newNode(10); 
    root->left = newNode(20); 
    root->right = newNode(30); 
  
    root->left->left = newNode(40); 
    root->left->right = newNode(50); 
    root->right->left = newNode(60); 
    root->right->right = newNode(70); 
  
    if (isPerfect(root)) 
        printf("Yes\n"); 
    else
        printf("No\n"); 
  
    return 0;
}