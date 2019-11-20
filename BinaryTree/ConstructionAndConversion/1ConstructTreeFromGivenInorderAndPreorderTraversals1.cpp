#include<iostream>

using namespace std;

class Node{
    public:
        char data;
        Node *left, *right;
};

Node* newNode(char data){
    Node* new_node = new Node();
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return new_node;
}

void printInorder(Node *root){
    if(root == NULL){
        return;
    }
    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}

int search(char arr[], int start, int end, char value){
    int i=0;
    for(i=start; i<=end; i++){
        if(arr[i] == value){
            return i;
        }
    }
    return i;
}

Node* buildTree(char in[], char pre[], int start, int end){
    static int preIndex = 0;

    if(start > end){
        return NULL;
    }

    Node *node = newNode(pre[preIndex]);
    preIndex++;

    if(start == end){
        return node;
    }

    int inIndex = search(in, start, end, node->data);

    node->left = buildTree(in, pre, start, inIndex - 1); 
    node->right = buildTree(in, pre, inIndex+1, end); 

    return node;
}

int main(){

    char in[] = {'D', 'B', 'E', 'A', 'F', 'C'};
    char pre[] = {'A', 'B', 'D', 'E', 'C', 'F'};

    int n = sizeof(in)/sizeof(in[0]);

    Node* root = buildTree(in, pre, 0, n-1);

    printInorder(root);
    cout<<endl;

    return 0;
}