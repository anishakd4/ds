#include<iostream>

using namespace std;

struct Node{
    int data;
    struct Node* next;
};

void printList(Node* node){
    cout<<"Creating Linked list: "<<endl;
    while(node != NULL){
        cout<<node->data<<endl;
        node = node->next;
    } 
}

void push(Node** head_ref, int new_data){
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = *head_ref;
    (*head_ref) = new_node;
}

void deleteNode(Node** head_ref, int position){
    if(*head_ref == NULL){
        return;
    }

    struct Node* temp = *head_ref;

    for (int i=0; temp!=NULL && i<position-1; i++) {
        temp = temp->next;
    }

    struct Node *next = temp->next->next; 
  
    free(temp->next);
  
    temp->next = next;  

}

int main(){

    struct Node* head = NULL;

    push(&head, 7);
    push(&head, 1);
    push(&head, 3);
    push(&head, 2);
    push(&head, 8);

    printList(head);
    deleteNode(&head, 4);
    printList(head);

    return 0;
}