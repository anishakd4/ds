#include<iostream>
#include<vector>
#include<queue>
#include<stack>

using namespace std;

class Node{
    public:
        int data;
        Node *left, *right;

        Node(int value){
            data = value;
            left = right = NULL;
        }
};

void specificLevelOrderTraversal(Node* root){
    if(root == NULL){
        return;
    }

    queue<Node *> q;

    stack<vector<int> > st;

    q.push(root);

    while(!q.empty()){
        vector<int> v;
        int sz = q.size();

        for(int i=0; i<sz; i++){
            Node* temp = q.front();
            q.pop();

            v.push_back(temp->data);

            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }

        st.push(v);
    }

    while(!st.empty()){
        vector <int> v = st.top(); 
        st.pop(); 

        for(int i=0,j=v.size()-1; i<j; i++, j--) { 
            cout<<v[i]<<" "<<v[j]<<" ";
        } 
    }
    cout<<root->data;
}

int main(){
    Node *root = new Node(1); 
  
    root->left = new Node(2); 
    root->right = new Node(3); 
  
    root->left->left = new Node(4); 
    root->left->right = new Node(5); 
    root->right->left = new Node(6); 
    root->right->right = new Node(7); 
  
    root->left->left->left = new Node(8); 
    root->left->left->right = new Node(9); 
    root->left->right->left = new Node(10); 
    root->left->right->right = new Node(11); 
    root->right->left->left = new Node(12); 
    root->right->left->right = new Node(13); 
    root->right->right->left = new Node(14); 
    root->right->right->right = new Node(15); 
  
    root->left->left->left->left = new Node(16); 
    root->left->left->left->right = new Node(17); 
    root->left->left->right->left = new Node(18); 
    root->left->left->right->right = new Node(19); 
    root->left->right->left->left = new Node(20); 
    root->left->right->left->right = new Node(21); 
    root->left->right->right->left = new Node(22); 
    root->left->right->right->right = new Node(23); 
    root->right->left->left->left = new Node(24); 
    root->right->left->left->right = new Node(25); 
    root->right->left->right->left = new Node(26); 
    root->right->left->right->right = new Node(27); 
    root->right->right->left->left = new Node(28); 
    root->right->right->left->right = new Node(29); 
    root->right->right->right->left = new Node(30); 
    root->right->right->right->right = new Node(31);

    cout << "Specific Level Order traversal of binary tree is \n"; 
    specificLevelOrderTraversal(root); 
    cout<<endl;

    return 0; 
}