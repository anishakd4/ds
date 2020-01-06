#include<iostream>
#include<map>
#include<vector>

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

void getVerticalOrder(map<int, vector<int> > &m, int hd, Node* root){
    if(root == NULL){
        return;
    }

    m[hd].push_back(root->data);

    getVerticalOrder(m, hd-1, root->left);
    getVerticalOrder(m, hd+1, root->right);
}

void printVerticalOrder(Node *root){
    map<int, vector<int> > m;
    int hd =0;
    getVerticalOrder(m, hd, root);

    map<int, vector<int> > :: iterator it;
    for(it = m.begin(); it!= m.end(); it++){
        for(int i=0; i < it->second.size(); i++){
            cout<<it->second[i]<<" ";
        }
        cout<<endl;
    }
}

int main(){

    Node *root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left = newNode(6); 
    root->right->right = newNode(7); 
    root->right->left->right = newNode(8); 
    root->right->right->right = newNode(9); 

    printVerticalOrder(root);
    cout<<endl;
    return 0;
}