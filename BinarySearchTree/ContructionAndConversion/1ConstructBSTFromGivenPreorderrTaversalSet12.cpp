#include<iostream>

using namespace std;

class Node{
    public:
        int data;
        Node *left, *right;
};

Node* newNode(int data){
    Node* new_node = new Node;
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

Node* constructTreeUtil(int pre[], int &preIndex, int key, int min, int max, int size){
    if(preIndex >= size){
        cout<<"NULL"<<endl;
        return NULL;
    }
    cout<<key<<" : "<<min<<" "<<max<<endl;

    Node* root = NULL;

    if(key > min && key < max){
        root = newNode(key);
        preIndex++;

        if(preIndex < size){
            root->left = constructTreeUtil(pre, preIndex, pre[preIndex], min, key, size);
            root->right = constructTreeUtil(pre, preIndex, pre[preIndex], key, max, size);
        }

    }

    return root;
}

Node* constructTree(int pre[], int n){
    int preIndex = 0;

    return constructTreeUtil(pre, preIndex, pre[preIndex], INT_MIN, INT_MAX, n);
}

int main(){

    int pre[] = {10, 5, 1, 7, 40, 50};  
    int size = sizeof( pre ) / sizeof( pre[0] );  
  
    Node* root = constructTree(pre, size);  
  
    cout << "Inorder traversal of the constructed tree: \n";  
    inorder(root);
    cout<<endl; 

    return 0;
}