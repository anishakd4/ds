#include<iostream>

using namespace std;

class Node{
    public:
        int data;
        Node *left, *right;

    Node(int data){
        left = right = NULL;
        this->data = data;
    }
};

void printInorder(Node* root){
    if(root == NULL){
        return;
    }
    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}

void increment(Node* node, int diff){
    if(node->left != NULL){
        node->left->data = node->left->data + diff;
        increment(node->left, diff);
    }else if(node->right != NULL){
        node->right->data = node->right->data + diff;
        increment(node->right, diff);
    }
}

void convertTree(Node *root){
    int left_data = 0, right_data = 0, diff;  

    if(root == NULL || (!root->left && !root->right)){
        return;
    }else{
        convertTree(root->left);
        convertTree(root->right);

        if(root->left != NULL){
            left_data = root->left->data;
        }

        if(root->right != NULL){
            right_data = root->right->data;
        }

        int diff = left_data + right_data - root->data;

        if(diff > 0){
            root->data = root->data + diff;
        }

        if(diff < 0){
            increment(root, -diff);
        }
        
    }
}

int main(){

    Node *root = new Node(50);  
    root->left = new Node(7);  
    root->right = new Node(2);  
    root->left->left = new Node(3);  
    root->left->right = new Node(5);  
    root->right->left = new Node(1);  
    root->right->right = new Node(30);  
      
    cout << "Inorder traversal before conversion: " << endl;  
    printInorder(root); 
    cout<<endl;
      
    convertTree(root);  
      
    cout << "Inorder traversal after conversion: " << endl;  
    printInorder(root);
    cout<<endl;

    return 0;
}