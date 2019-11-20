#include<iostream>
#include<queue>

using namespace std;

class Node{
    public:
        int data;
        Node *left, *right;
};

Node* newNode(int data){
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

void printLevelOrderLineByLine(Node* root){
    if(root == NULL){
        return;
    }
    queue<Node *> q1, q2;
    q1.push(root);

    while(!q1.empty() || !q2.empty()){

        while(!q1.empty()){
            if (q1.front()->left != NULL) { 
                q2.push(q1.front()->left); 
            }
  
            if (q1.front()->right != NULL) {
                q2.push(q1.front()->right);
            }
  
            cout << q1.front()->data << " "; 
            q1.pop(); 
        }

        cout<<endl;

        while(!q2.empty()){
            if (q2.front()->left != NULL) { 
                q1.push(q2.front()->left); 
            }
  
            if (q2.front()->right != NULL) {
                q1.push(q2.front()->right);
            }
  
            cout << q2.front()->data << " "; 
            q2.pop(); 
        }

        cout<<endl;
    }
}

Node* constructTreeUtil(int pre[], int post[], int &preIndex, int start, int end, int n){
    if(preIndex >= n || start > end){
        return NULL;
    }

    Node *root = newNode(pre[preIndex]);
    preIndex++;

    if(start == end){
        return root;
    }

    int i=-1;
    for(i=start; i<=end; i++){
        if(pre[preIndex] == post[i]){
            break;
        }
    }

    if(i != -1 && i <= end){
        root->left = constructTreeUtil(pre, post, preIndex, start, i, n);
        root->right = constructTreeUtil(pre, post, preIndex, i+1, end, n);
    }

    return root;
}

Node* constructTree(int pre[], int post[], int n){
    int preIndex = 0;
    return constructTreeUtil(pre, post, preIndex, 0, n-1, n);
}

int main(){

    int pre[] = {1, 2, 4, 8, 9, 5, 3, 6, 7};  
    int post[] = {8, 9, 4, 5, 2, 6, 7, 3, 1};  
    int size = sizeof( pre ) / sizeof( pre[0] ); 
  
    Node *root = constructTree(pre, post, size); 
  
    cout<<"Inorder traversal of the constructed tree: \n";  
    printInorder(root);  
    cout<<endl;

    cout<<endl;
    cout<<endl;
    printLevelOrderLineByLine(root);
    cout<<endl;
  
    return 0;  
}