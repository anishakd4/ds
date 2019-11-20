#include<iostream>
#include<queue>

using namespace std;

struct ListNode{
    int data;
    ListNode* next;
};

struct BinaryNode{
    int data;
    BinaryNode *left, *right;
};

void push(ListNode **head, int data){
    ListNode* new_node = new ListNode;
    new_node->data = data;
    new_node ->next = *head;
    *head = new_node;
}

BinaryNode* newTreeNode(int data){
    BinaryNode* new_node = new BinaryNode;
    new_node->data = data;
    new_node->left = new_node->right;
    return new_node;
}

void inorderTraversal(BinaryNode *root){
    if(root == NULL){
        return;
    }
    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);
}

void convertList2Binary(ListNode *head, BinaryNode* &root){
    queue<BinaryNode *> q;

    if(head == NULL){
        return;
    }

    root = newTreeNode(head->data);
    q.push(root);

    head = head->next;

    while(head){
        BinaryNode* parent = q.front();
        q.pop();

        BinaryNode *leftChild = newTreeNode(head->data);
        parent->left = leftChild;
        q.push(leftChild);
        head = head->next;

        if(head){
            BinaryNode *rightChild = newTreeNode(head->data);
            parent->right = rightChild;
            q.push(rightChild);
            head = head->next;
        }
    }
}

int main(){

    struct ListNode* head = NULL; 
    push(&head, 36);
    push(&head, 30); 
    push(&head, 25); 
    push(&head, 15); 
    push(&head, 12); 
    push(&head, 10);
  
    BinaryNode *root; 
    convertList2Binary(head, root); 
  
    cout << "Inorder Traversal of the constructed Binary Tree is: \n"; 
    inorderTraversal(root); 
    cout<<endl;
    
    return 0;
}