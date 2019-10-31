#include<iostream>

using namespace std;

struct Node{
    int data;
    struct Node* next;
};

void printList(struct Node* node){
    cout<<"Linked List: "<<endl;
    while (node != NULL){
        cout<<node->data<<endl;
        node = node->next;
    }
}

void push(struct Node** head_ref, int new_data){
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void deleteNode(struct Node** head_ref, int key){
    struct Node* temp = *head_ref, *prev;

    while(temp != NULL && temp->data !=key){
        prev = temp;
        temp = temp->next;
    }

    if(temp  == NULL){
        return;
    }

    prev->next = temp->next;
    
    free(temp);
}

int main(){

    struct Node* head = NULL;

    push(&head, 7);
    push(&head, 1);
    push(&head, 3);
    push(&head, 2);

    printList(head);
    deleteNode(&head, 1);
    printList(head);

    return 0;
}