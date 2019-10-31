#include<iostream>

using namespace std;

class Node{
    public:
        int data;
        Node* next;
};

void push(Node** head_ref, int new_data){
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

void printList(Node* node){
    cout<<"Linked list: "<<endl;
    while (node !=  NULL){
        cout<<node->data<<endl;
        node = node->next;
    }
}

void removeDuplicates(Node* head){
    if(head == NULL){
        return;
    }

    if(head->next != NULL){
        if(head->data == head->next->data){
            Node* temp = head->next;
            head->next = head->next->next;
            free(temp);
            removeDuplicates(head);
        }else{
            removeDuplicates(head->next);
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