#include<iostream>
#include<queue>

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

bool areIdentical(Node* root1, Node* root2){
    if(root1 == NULL && root2 == NULL){
        return true;
    }

    if(root1 == NULL || root2 == NULL){
        return false;
    }
    queue<Node *> q1, q2;
    q1.push(root1);
    q2.push(root2);

    while(!q1.empty() && !q2.empty()){
        Node* n1 = q1.front();
        Node* n2 = q2.front();
        q1.pop(); q2.pop();

        if(n1->data != n2->data){
            return false;
        }

        if(n1->left && n2->left){
            q1.push(n1->left);
            q2.push(n2->left);
        }else if(n1->left || n2->left){
            return false;
        }

        if(n1->right && n2->right){
            q1.push(n1->right);
            q2.push(n2->right);
        }else if(n1->right || n2->right){
            return false;
        }
    }

    return true;
}

int main(){

    Node *root1 = newNode(1); 
    root1->left = newNode(2); 
    root1->right = newNode(3); 
    root1->left->left = newNode(4); 
    root1->left->right = newNode(5); 
  
    Node *root2 = newNode(1); 
    root2->left = newNode(2); 
    root2->right = newNode(3); 
    root2->left->left = newNode(4); 
    root2->left->right = newNode(5); 
  
    areIdentical(root1, root2)? cout << "Yes" : cout << "No";
    cout<<endl;

    return 0;
}