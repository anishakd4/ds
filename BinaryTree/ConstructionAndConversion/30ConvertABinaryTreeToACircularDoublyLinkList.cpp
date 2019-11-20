#include<iostream>
#include<queue>

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

void displayCList(Node* head){
    cout << "Circular Linked List is :\n"; 
    Node *itr = head; 
    do
    { 
        cout << itr->data <<" "; 
        itr = itr->right; 
    } while (head!=itr); 
    cout << "\n";
}

void bTreeToCListUtil(Node* root, queue<Node *> &qu){
    if(root == NULL){
        return;
    }
    bTreeToCListUtil(root->left, qu);
    qu.push(root);
    bTreeToCListUtil(root->right, qu);
}

Node* bTreeToCList(Node* root){
    if(root == NULL){
        return NULL;
    }
    queue<Node *> qu;
    bTreeToCListUtil(root, qu);

    Node *topi= qu.front();
    Node *t1= qu.front();
    qu.pop();

    while(!qu.empty()){
        Node *t2= qu.front();
        qu.pop();
        t1->right = t2;
        t2->left = t1;
        t1 = t2;
    }

    topi->left = t1;
    t1->right = topi;

    return topi;
}

int main(){

    Node *root = newNode(10); 
    root->left = newNode(12); 
    root->right = newNode(15); 
    root->left->left = newNode(25); 
    root->left->right = newNode(30); 
    root->right->left = newNode(36); 
  
    Node *head = bTreeToCList(root); 
    displayCList(head); 

    return 0;
}