#include<iostream>

using namespace std;

class LNode{
    public:
        int data;
        LNode* next;
};

class TNode{
    public:
        int data;
        TNode *left, *right;
};

TNode* newNode(int data){
    TNode* new_node = new TNode();
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return new_node;
}

void preOrder(TNode* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void printList(LNode* head){
    cout<<"Linked list: "<<endl;
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

void push(LNode** head, int data){
    LNode* temp = new LNode();
    temp->data = data;
    temp->next = *head;
    *head = temp;
}

int countNodes(LNode* head){
    int i=0;
    while(head != NULL){
        i++;
        head = head->next;
    }
    return i;
}

TNode* sortedListToBSTUtil(LNode* &head, int n){
    if(n <= 0){
        return NULL;
    }

    TNode* left = sortedListToBSTUtil(head, n/2);

    TNode* root = newNode(head->data);
    root->left = left;

    head = head->next;

    root->right = sortedListToBSTUtil(head, n - n/2 - 1);

    return root;
}

TNode* sortedListToBST(LNode* head){
    int n = countNodes(head);
    cout<<"n: "<<n<<endl;

    return sortedListToBSTUtil(head, n);
}

int main(){

    LNode* head = NULL;  
  
    push(&head, 7);  
    push(&head, 6);  
    push(&head, 5);  
    push(&head, 4);  
    push(&head, 3);  
    push(&head, 2);  
    push(&head, 1);  
   
    printList(head);  
  
    TNode *root = sortedListToBST(head);

    cout<<"PreOrder Traversal of constructed BST \n";  
    preOrder(root);
    cout<<endl;

    return 0;
}