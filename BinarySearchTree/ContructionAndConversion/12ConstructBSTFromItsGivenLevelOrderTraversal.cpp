#include<iostream>
#include<vector>

using namespace std;

struct Node{
    int data;
    Node *left, *right;
};

Node* newNode(int data){
    Node* new_node = new Node;
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return new_node;
}

void inorderTraversal(Node* root){
    if(root == NULL){
        return;
    }
    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);
}

Node* levelOrderToBst(Node* root, int data){
    if(root == NULL){
        return newNode(data);
    }
    if(data < root->data){
        root->left = levelOrderToBst(root->left, data);
    }else{
        root->right = levelOrderToBst(root->right, data);
    }
    return root;
}

// bool isLeftOk(Node* root, int data){
//     if(root->left == NULL && root->data > data){
//         return true;
//     }
//     return false;
// }

// bool isRightOk(Node* root, int data){
//     if(root->right == NULL && root->data < data){
//         return true;
//     }
//     return false;
// }

Node* constructBst(int arr[], int n){
    if(n == 0){
        return NULL;
    }

    Node* root = NULL;

    for(int i=0; i<n; i++){
        root = levelOrderToBst(root, arr[i]);
        cout<<root->data<<" : "<<arr[i]<<endl;
    }

    // Node* root = newNode(arr[0]);
    // vector<Node *> q;
    // q.push_back(root);
    // int curr = 0;

    // for(int i=1; i<n; i++){
    //     if(isLeftOk(q[curr], arr[i])){
    //         q[curr]->left = newNode(arr[i]);
    //         q.push_back(q[curr]->left);
    //     }else if(isRightOk(q[curr], arr[i])){
    //         q[curr]->right = newNode(arr[i]);
    //         q.push_back(q[curr]->right);
    //         curr++;
    //     }else{
    //         curr++;
    //         i--;
    //     }
    // }

    return root;
}

int main(){

    int arr[] = {7, 4, 12, 3, 6, 8, 1, 5, 10}; 
    int n = sizeof(arr) / sizeof(arr[0]); 
      
    Node *root = constructBst(arr, n); 
      
    cout << "Inorder Traversal: "; 
    inorderTraversal(root);
    cout<<endl;

    return 0;
}