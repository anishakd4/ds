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

void modifiedLevelOrder(Node* root){
    if(root == NULL){
        return;
    }

    if(root->left == NULL && root->right == NULL){
        cout<<root->data<<" ";
        return;
    }

    queue<Node *> q;
    stack<Node *> st;

    int ct = 0;

    q.push(root);

    bool rightToLeft = false;

    while(!q.empty()){
        ct++; 
        int sz = q.size();

        for(int i=0; i<sz; i++){
            Node* temp = q.front();
            q.pop();

            if (rightToLeft == false){
                cout << temp->data << " ";  
            }else {
                st.push(temp); 
            }

            if(temp->left != NULL){
                q.push(temp->left);
            }
            if(temp->right != NULL){
                q.push(temp->right);
            }
        }

        if (rightToLeft == true) { 
            while (!st.empty()) { 
                Node* temp = st.top(); 
                st.pop(); 
  
                cout << temp->data << " "; 
            } 
        }

        if (ct == 2) { 
            rightToLeft = !rightToLeft; 
            ct = 0; 
        } 
        cout<<endl;
    }

}

int main(){

    Node* root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left = newNode(6); 
    root->right->right = newNode(7); 
    root->left->left->left = newNode(8); 
    root->left->left->right = newNode(9); 
    root->left->right->left = newNode(3); 
    root->left->right->right = newNode(1); 
    root->right->left->left = newNode(4); 
    root->right->left->right = newNode(2); 
    root->right->right->left = newNode(7); 
    root->right->right->right = newNode(2); 
    root->left->right->left->left = newNode(16); 
    root->left->right->left->right = newNode(17); 
    root->right->left->right->left = newNode(18); 
    root->right->right->left->right = newNode(19); 
  
    modifiedLevelOrder(root); 

    return 0;
}