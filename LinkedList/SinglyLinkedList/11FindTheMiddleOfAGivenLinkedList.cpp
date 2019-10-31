#include<iostream>

using namespace std;

struct Node {
    int data;
    struct Node* next;
};

void printList(Node* node){
    cout<<"Linked List: "<<endl;
    while(node != NULL){
        cout<<node->data<<endl;
        node = node->next;
    }
}

void push(Node** head_ref, int new_data){
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

void printMiddle(Node* head){
    struct Node* slow_ptr = head;
    struct Node* fast_ptr = head;

    if(head != NULL){
        while (fast_ptr != NULL && fast_ptr->next != NULL){
            fast_ptr = fast_ptr->next->next;
            slow_ptr = slow_ptr->next;   
        }
        cout<<"Middle element is : "<<slow_ptr->data<<endl;
    }
}

int main(){
    struct Node* head = NULL;
    int i;

    for(int i=5; i>0; i--){
        push(&head, i);
        printList(head);
        printMiddle(head);
    }   

    return 0;
}