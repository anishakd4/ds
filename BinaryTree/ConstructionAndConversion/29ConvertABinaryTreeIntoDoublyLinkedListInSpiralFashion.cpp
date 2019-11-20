#include<iostream>
#include<stack>
#include<queue>

using namespace std;

struct Node{
    int data;
    struct Node *left, *right;
};

Node* newNode(int data){
    Node* new_node = new Node;
    new_node->data = data;
    new_node->left = new_node->right;
    return new_node;
}

void printList(Node *node){
    while(node != NULL){
        cout<<node->data<<" ";
        node = node->right;
    }
}

void spiralLevelOrder(Node* root){

    if(root == NULL){
        return;
    }
    deque<Node *> dq;
    stack<Node *> st;

    dq.push_front(root);

    int flag = 1;

    while(!dq.empty()){

        int nodeCount = dq.size();

        if(flag == 1){
            flag = 2;

            while(nodeCount > 0){
                Node* temp = dq.front();
                dq.pop_front();
                st.push(temp);
                if(temp->left){
                    dq.push_back(temp->left);
                }
                if(temp->right){
                    dq.push_back(temp->right);
                }
                nodeCount--;
            }
            
        }else{
            flag = 1;
            while(nodeCount > 0){
                Node* temp = dq.back();
                dq.pop_back();
                st.push(temp);
                if(temp->right){
                    dq.push_front(temp->right);
                }
                if(temp->left){
                    dq.push_front(temp->left);
                }
                nodeCount--;
            }
        }
    }

    Node *t = st.top();
    st.pop();

    while(!st.empty()){
        Node *t2 = st.top();
        st.pop();
        t2->right = t;
        t->left = t2;
        t = t2;
    }
  
    cout << "Created DLL is:\n"; 
    printList(root);
    cout<<endl;
}

int main(){

    Node *root =  newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left = newNode(6); 
    root->right->right = newNode(7); 
  
    root->left->left->left  = newNode(8); 
    root->left->left->right  = newNode(9); 
    root->left->right->left  = newNode(10); 
    root->left->right->right  = newNode(11); 
    //root->right->left->left  = newNode(12); 
    root->right->left->right  = newNode(13); 
    root->right->right->left  = newNode(14); 

    spiralLevelOrder(root); 


    return 0;
}