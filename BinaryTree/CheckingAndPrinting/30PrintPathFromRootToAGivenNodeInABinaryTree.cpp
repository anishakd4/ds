#include<iostream>
#include<vector>

using namespace std;

struct Node{
    int data;
    Node *left, *right;
};

struct Node* getNode(int data){
    Node* new_node = new Node;
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return new_node;
}

void printVector(vector<int> vec){
    for(int i=0; i<vec.size(); i++){
        cout<<vec[i]<<" ";
    }
    cout<<endl;
}

bool hasPath(Node* root, vector<int> &arr, int x){
    if(root == NULL){
        return false;
    }

    arr.push_back(root->data);

    if(root->data == x){
        return true;
    }

    if(hasPath(root->left, arr, x) || hasPath(root->right, arr, x)){
        return true;
    }else{
        arr.pop_back();
        return false;
    }
    
}

void printPath(Node* root, int x){

    vector<int> arr;

    if(hasPath(root, arr, x)){
        printVector(arr);
    }else{
        cout<<"No path"<<endl;
    }
    
}

int main(){

    struct Node *root = getNode(1); 
    root->left = getNode(2); 
    root->right = getNode(3); 
    root->left->left = getNode(4); 
    root->left->right = getNode(5); 
    root->right->left = getNode(6); 
    root->right->right = getNode(7); 
          
    int x = 5; 
    printPath(root, x); 

    return 0;
}