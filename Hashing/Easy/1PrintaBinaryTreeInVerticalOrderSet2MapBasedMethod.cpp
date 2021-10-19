#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

Node* newNode(int data)
{
    struct Node* node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return node;
};

void getVerticalOrder(map<int, vector<int> > &m, Node* root, int hd){
    if(root == NULL){
        return;
    }
    m[hd].push_back(root->data);
    getVerticalOrder(m, root->left, hd-1);
    getVerticalOrder(m, root->right, hd+1);
}

void printVerticalOrder(Node* root){
    map<int, vector<int> > m;
    int hd = 0;
    getVerticalOrder(m, root, hd);
    map<int, vector<int> > :: iterator it;
    for(it=m.begin(); it!=m.end(); it++){
        for(int i=0; i<it->second.size(); i++){
            cout<<it->second[i]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    Node* root = newNode(1);
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left = newNode(6); 
    root->right->right = newNode(7); 
    root->right->left->right = newNode(8); 
    root->right->right->right = newNode(9); 

    printVerticalOrder(root); 
    return 0;
}