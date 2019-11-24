#include<iostream>
#include<string>
#include<vector>
#define MARKER -1

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

void inorder(Node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void deSerialize(Node* &root, vector<int> vec, int &index){
    if(index > vec.size() || vec[index] == -1){
        index++;
        return;
    }
    root = newNode(vec[index]);
    index++;
    deSerialize(root->left, vec, index); 
    deSerialize(root->right, vec, index);
}

void serialize(Node *root, vector<int> &vec){
    if(root == NULL){
        vec.push_back(-1);
        return;
    }
    vec.push_back(root->data);
    serialize(root->left, vec);
    serialize(root->right, vec);
}

int main(){

    struct Node *root        = newNode(20); 
    root->left               = newNode(8); 
    root->right              = newNode(22); 
    root->left->left         = newNode(4); 
    root->left->right        = newNode(12); 
    root->left->right->left  = newNode(10); 
    root->left->right->right = newNode(14); 

    vector<int> vec; 
    serialize(root, vec);
    cout<<vec.size()<<endl;
    for(int i=0; i<vec.size(); i++){
        cout<<vec[i]<<" ";
    }
    cout<<endl;

    Node* root1 = NULL;
    int index = 0;
    deSerialize(root1, vec, index);
    inorder(root1);
    cout<<endl;

    return 0;
}