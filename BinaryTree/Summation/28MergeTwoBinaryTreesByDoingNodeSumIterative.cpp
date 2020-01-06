#include<iostream>
#include<stack>

using namespace std;

struct Node{
    int data;
    Node *left, *right;
};

struct SNode{
    Node *l, *r;
};

void inorder(Node* node){
    if(node == NULL){
        return;
    }
    inorder(node->left);
    cout<<node->data<<" ";
    inorder(node->right);
}

Node* newNode(int data){
    Node* new_node = new Node;
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return new_node;
}

Node* MergeTrees(Node* t1, Node* t2){
    if(t1 == NULL){
        return t1;
    }
    if(t2 == NULL){
        return t1;
    }

    stack<SNode> st;
    SNode s;
    s.l = t1;
    s.r = t2;

    st.push(s);

    SNode n;

    while(!st.empty()){
        n = st.top();
        st.pop();

        if(n.l == NULL || n.r == NULL){
            continue;
        }
        n.l->data = n.l->data + n.r->data;
        if(n.l->left == NULL){
            n.l->left = n.r->left;
        }else{
            SNode t;
            t.l = n.l->left;
            t.r = n.r->left;
            st.push(t);
        }

        if(n.l->right == NULL){
            n.l->right = n.r->right;
        }else{
            SNode t;
            t.l = n.l->right;
            t.r = n.r->right;
            st.push(t);
        }
    }
    return t1;
}

int main(){

    Node *root1 = newNode(1); 
    root1->left = newNode(2); 
    root1->right = newNode(3); 
    root1->left->left = newNode(4); 
    root1->left->right = newNode(5); 
    root1->right->right = newNode(6); 
   
    
    Node *root2 = newNode(4); 
    root2->left = newNode(1); 
    root2->right = newNode(7); 
    root2->left->left = newNode(3); 
    root2->right->left = newNode(2); 
    root2->right->right = newNode(6); 
   
    Node *root3 = MergeTrees(root1, root2); 
    printf("The Merged Binary Tree is:\n"); 
    inorder(root3); 
    cout<<endl;

    return 0;
}