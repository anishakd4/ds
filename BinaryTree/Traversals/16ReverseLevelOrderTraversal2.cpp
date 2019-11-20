#include<iostream>
#include<queue>
#include<stack>

using namespace std;

struct Node{
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int data){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return new_node;
}

void reverseLevelOrder(Node *root){
    stack<Node *> st;
    queue<Node *> q;

    q.push(root);

    while(!q.empty()){
        Node *temp = q.front();
        q.pop();

        st.push(temp);

        if(temp->right){
            q.push(temp->right);
        }

        if(temp->left){
            q.push(temp->left);
        }
    }

    while (st.empty() == false) { 
        root = st.top(); 
        cout << root->data << " "; 
        st.pop(); 
    } 

}

int main(){

    struct Node *root = newNode(1); 
    root->left        = newNode(2); 
    root->right       = newNode(3); 
    root->left->left  = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left  = newNode(6); 
    root->right->right = newNode(7); 
  
    cout << "Level Order traversal of binary tree is "<<endl; 
    reverseLevelOrder(root); 
    cout<<endl;

    return 0;
}