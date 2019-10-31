#include<iostream>

using namespace std;

struct Node{
    int data;
    struct Node* next;
};

void push(Node** head_ref, int new_data){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;   
}

int count(Node* head, int x){
    if(head == NULL){
        return 0;
    }
    if(head->data == x){
        return (1+ count(head->next, x));
    }
    return count(head->next, x);
}

int main(){
    struct Node* head = NULL;

    push(&head, 1); 
    push(&head, 3); 
    push(&head, 1); 
    push(&head, 2); 
    push(&head, 1); 

    cout << "count of 1 is " << count(head, 1)<<endl;

    return 0;
}