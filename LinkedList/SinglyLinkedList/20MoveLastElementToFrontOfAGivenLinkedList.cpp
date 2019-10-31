#include<iostream>

using namespace std;

class Node{
    public:
        int data;
        Node* next;
};

void printList(Node* node){
    cout<<"Linked list: "<<endl;
    while(node !=  NULL){
        cout<<node->data<<endl;
        node = node->next;
    }
}

void push(Node** head_ref, int new_data){
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

void moveToFront(Node** head_ref){
    if(*head_ref == NULL || (*head_ref)->next == NULL){
        return;
    }

    Node* secondlast = NULL;
    Node* last = *head_ref;

    while(last->next != NULL){
        secondlast = last;
        last = last->next;
    }

    secondlast->next = NULL;
    last->next = *head_ref;
    *head_ref = last;
}

int main(){
    Node* head = NULL;

    push(&head, 5);  
    push(&head, 4);  
    push(&head, 3);  
    push(&head, 2);  
    push(&head, 1); 

    printList(head);

    moveToFront(&head);

    printList(head);
}