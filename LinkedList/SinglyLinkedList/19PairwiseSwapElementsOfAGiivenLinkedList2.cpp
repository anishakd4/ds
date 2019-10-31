#include<iostream>

using namespace std;

struct Node{
    int data;
    struct Node* next;
};

void printList(Node* node){
    cout<<"Linked List: "<<endl;
    while (node != NULL){
        cout<<node->data<<endl;
        node=node->next;
    }
}

void push(Node** head_ref, int new_data){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

void pairWiseSwap(struct Node* head){
    if(head != NULL && head->next != NULL){
        swap(head->data, head->next->data);
        pairWiseSwap(head->next->next);
    }
}

int main(){

    struct Node* head = NULL;

    push(&head, 5); 
    push(&head, 4); 
    push(&head, 3); 
    push(&head, 2); 
    push(&head, 1);

    printList(head);

    pairWiseSwap(head);

    printList(head);
    
    return 0;
}