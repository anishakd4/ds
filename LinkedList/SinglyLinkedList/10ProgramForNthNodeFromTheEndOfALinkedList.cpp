#include<iostream>

using namespace std;

struct Node{
    int data;
    struct Node* next;
};

void push(struct Node** head_ref, int new_data){
    struct Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

void printNthFromLast(Node *head, int n){
    struct Node* ref_ptr = head;
    struct Node* main_ptr = head;

    int count = 0;

    if(head != NULL){
        while(count < n){
            if(ref_ptr == NULL){
                printf("%d is greater than the no. of nodes in list", n);
                return;
            }
            ref_ptr = ref_ptr->next;
            count++;
        }

        while(ref_ptr != NULL) { 
            main_ptr = main_ptr->next; 
            ref_ptr  = ref_ptr->next; 
        } 
        printf("Node no. %d from last is %d ", n, main_ptr->data); 
    }
}

int main(){

    struct Node* head = NULL;

    push(&head, 20);
    push(&head, 4);
    push(&head, 15);
    push(&head, 35);

    printNthFromLast(head, 4); 

    return 0;
}