#include<iostream>
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

int diameterUtil(Node* root, Node* &node, int &ans, int &lHeight, int &rHeight){
    if(root == NULL){
        return 0;
    }

    int left_height = diameterUtil(root->left, node, ans, lHeight, rHeight); 
  
    int right_height = diameterUtil(root->right, node, ans, lHeight, rHeight); 

    if(ans < (1 + left_height + right_height)){
        ans = 1 + left_height + right_height;
        lHeight = left_height;
        rHeight = right_height;
        node = root;
    }

    return (1 + max(left_height, right_height));
}

void printArray(vector<int> ints, int f) {
    //cout<<"printArray"<<endl;
    if(f == 0){
        for(int i=ints.size()-1; i>=0; i--){
            cout<<ints[i]<<" ";
        }
    }
    if(f == 1){
        for(int i=0; i<ints.size(); i++){
            cout<<ints[i]<<" ";
        }
    }
}

void findPath(Node *node, int height, vector<int> &path, int &f){
    if(node == NULL){
        return;
    }
    //cout<<node->data<<endl;
    // cout<<"path.size: "<<path.size()<<endl;
    // cout<<"height: "<<height<<endl;

    path.push_back(node->data);

    if(node->left == NULL && node->right == NULL){
        if(path.size() == height && (f == 0 || f == 1)){
            printArray(path, f); 
            f = 2; 
        }
    }else{
        findPath(node->left, height, path, f);
        findPath(node->right, height, path, f);
    }
}

void diameter(Node* root){
    //cout<<root->data<<endl;
    if(root == NULL){
        return;
    }

    int lHeight = 0, rHeight = 0, ans = 0;
    Node* node;

    int f=0;
    diameterUtil(root, node, ans, lHeight, rHeight);
    // cout<<node->data<<endl;
    // cout<<ans<<endl;
    // cout<<"lHeight: "<<lHeight<<endl;
    // cout<<"rHeight: "<<rHeight<<endl;
    // cout<<"----"<<endl;

    vector<int> lPath, rPath;
    findPath(node->left, lHeight, lPath, f);

    cout<<node->data<<" ";
    f=1;
    findPath(node->right, rHeight, rPath, f);
    cout<<endl;

}

int main(){

    struct Node* root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->left->right->left = newNode(6); 
    root->left->right->right = newNode(7); 
    root->left->left->right = newNode(8); 
    root->left->left->right->left = newNode(9); 
  
    diameter(root); 

    return 0;
}