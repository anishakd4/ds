#include<iostream>

using namespace std;

class Node{
    public:
        int data;
        Node* next;
};

void printList(Node* node){
    cout<<"Linked List: "<<endl;
    while(node != NULL){
        cout<<node->data<<endl;
        node = node->next;
    }
    cout<<endl;
} 

void push(Node** head_ref, int new_data){
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = *head_ref;

    *head_ref = new_node;
} 

void append(Node** head_ref, int new_data){
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = NULL;

    if(*head_ref == NULL){
        *head_ref = new_node;
        return;
    }

    Node* last = *head_ref;
    while (last->next != NULL){
        last = last->next;
    }
    
    last->next = new_node;
    return;
}

void insertAfter(Node* prev_node, int new_data){
    if(prev_node == NULL){
        cout<<"Given previous node can not be null"<<endl;
        return;
    }

    Node *new_node = new Node();
    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

int main(){

    Node* head = NULL;

    append(&head, 6);
    push(&head, 7);
    push(&head, 1);
    append(&head, 4);
    insertAfter(head->next, 8);

    printList(head);

    return 0;
}