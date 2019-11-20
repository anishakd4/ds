#include<iostream>

using namespace std;

struct Node{
    int data;
    Node *left, *right;
};

struct Node* newNode(int data){
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

void inorder(Node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

Node* createTree(int parent[], int n){
    Node* nodes[n];

    Node *root = NULL;

    for(int i=0; i<n; i++){
        nodes[i] = newNode(i);
    }

    for(int i=0; i<n; i++){
        if(parent[i] == -1){
            root = nodes[i];
        }else{
            if(!nodes[parent[i]]->left){
                nodes[parent[i]]->left = nodes[i];
            }else{
                nodes[parent[i]]->right = nodes[i];
            }
        }
    }

    return root;
}

int main(){

    int parent[] =  {-1, 0, 0, 1, 1, 3, 5}; 
    int n = sizeof parent / sizeof parent[0]; 

    Node *root = createTree(parent, n); 

    cout << "Inorder Traversal of constructed tree\n"; 
    inorder(root);
    cout<<endl;
    return 0;
}