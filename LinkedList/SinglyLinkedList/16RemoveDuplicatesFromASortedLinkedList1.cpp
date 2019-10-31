#include<iostream>

using namespace std;

class Node{
    public:
        int data;
        Node* next;
};

void printList(Node* node){
    cout<<"Linked list: "<<endl;
    while (node != NULL){
        cout<<node->data<<endl;
        node = node->next;
    }
}

void push(Node** head_ref, int new_data){
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next=*head_ref;
    *head_ref = new_node;
}

void removeDuplicates(Node* head_ref){
    Node* current = head_ref;

    Node* next_ptr = head_ref;

    if(current == NULL){
        return;
    }

    while (current->next != NULL){
        if(current->data == current->next->data){
            next_ptr = current->next->next;
            free(current->next);
            current->next = next_ptr;
        }else{
            current = current->next;
        }
    }
}

int main(){

    Node* head = NULL;

    push(&head, 20);  
    push(&head, 13);  
    push(&head, 13);  
    push(&head, 11);  
    push(&head, 11);  
    push(&head, 11);

    printList(head);

    removeDuplicates(head);

    printList(head);

    return 0;
}