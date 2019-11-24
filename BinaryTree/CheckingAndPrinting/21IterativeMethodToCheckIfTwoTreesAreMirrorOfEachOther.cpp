#include<iostream>
#include<stack>

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

string areMirrors(Node *a, Node *b){
    stack<Node *> st1, st2;

    while(1){
        while(a && b){
            if(a->data != b->data){
                return "No";
            }
            st1.push(a);
            st2.push(b);
            a=a->left;
            b=b->right;
        }
        if(!(a== NULL && b == NULL)){
            return "No";
        }
        if(!st1.empty() && !st2.empty()){
            a = st1.top();
            st1.pop();
            b = st2.top();
            st2.pop();

            a = a->right;
            b = b->left;
        }else{
            break;
        }
    }

    // while(a || !st.empty()){
    //     while(a){
    //         st.push(a);
    //         a = a->left;
    //     }
    //     a = st.top();
    //     st.pop();
    //     cout<<a->data<<" ";
    //     a = a->right;
    // }
    return "Yes";
}

int main(){

    Node *root1 = newNode(1);                               
    root1->left = newNode(3);          
    root1->right = newNode(2);          
    root1->right->left = newNode(5);    
    root1->right->right = newNode(4);    


    Node *root2 = newNode(1);           
    root2->left = newNode(2);           
    root2->right = newNode(3);          
    root2->left->left = newNode(4); 
    root2->left->right = newNode(5); 

    // areMirrors(root1, root2);
    // cout<<endl;
          
    cout << areMirrors(root1, root2);
    cout<<endl;

    return 0;
}