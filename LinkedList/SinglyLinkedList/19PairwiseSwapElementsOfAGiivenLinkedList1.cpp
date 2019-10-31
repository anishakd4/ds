#include<iostream>

using namespace std;

class Node{
    public:
        int data;
        Node* next; 
};

void printList(Node* node){
    cout<<"Linked list: "<<endl;
    while(node != NULL){
        cout<<node->data<<endl;
        node = node->next;
    }
}

void push(Node** head_ref, int new_data){
    Node* new_node = new Node();
    new_node->data =  new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

void pairWiseSwap(Node* head){
    Node* temp = head;

    while(temp != NULL && temp->next != NULL){
        swap(temp->data, temp->next->data);
        temp = temp->next->next;
    }
}

int main(){
    Node* head = NULL;

    push(&head, 5); 
    push(&head, 4); 
    push(&head, 3); 
    push(&head, 2); 
    push(&head, 1);

    printList(head);

    pairWiseSwap(head);

    printList(head);
}