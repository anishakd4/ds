#include<iostream>
#include<string>
#include<stack>

using namespace std;

struct Node{
    int data;
    Node *left, *right;
};

Node* newNode(int data){
    Node* new_node = new Node;
    new_node->data=data;
    new_node->left = new_node->right = NULL;
    return new_node;
}

void preOrder(Node* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

int findIndex(string str, int start, int end){
    if(start > end){
        return -1;
    }

    stack<int> st;

    for(int i=start; i<=end; i++){
        if(str[i] == '('){
            st.push(str[i]);
        }else if(str[i] == ')'){
            if(st.top() == '('){
                st.pop();

                if(st.empty()){
                    return i;
                }
            }
        }
    }

    return -1;
    
}

Node* treeFromString(string str, int start, int end){
    if(start > end){
        return NULL;
    }

    Node* root = newNode(str[start] - '0');
    int index = -1;

    if(str[start + 1] == '(' && start+1 <= end){
        index = findIndex(str, start+1, end);
    }

    if(index != -1){
        root->left = treeFromString(str, start+2, index-1);
        root->right = treeFromString(str, index+2, end-1);
    }

    return root;
}

int main(){

    string str = "4(2(3)(1))(6(5))"; 
    Node *root = treeFromString(str, 0, str.length()-1);

    preOrder(root);
    cout<<endl;

    return 0;
}