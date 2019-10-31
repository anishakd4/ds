#include<iostream>

using namespace std;

struct Node{
    int data;
    struct Node* next;
};

void printList(struct Node* node){
    cout<<"Linked List: "<<endl;
    while(node != NULL){
        cout<<node->data<<endl;
        node = node->next;
    }
}

void push(struct Node** head_ref, int new_data){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

struct Node* sortedIntersect(struct Node* a, struct Node* b){
    struct Node* dummy = NULL;
    struct Node** tail = &dummy;
    while (a != NULL && b != NULL){
        if(a->data == b->data){
            push(tail, a->data);
            tail=&((*tail)->next);
            a=a->next;
            b=b->next;
        }else if(a->data > b->data){
            b = b->next;
        }else{
            a = a->next;
        }
    }
    return dummy;
}

int main(){

    struct Node* a = NULL;
    struct Node* b = NULL;
    struct Node* intersect = NULL;

    push(&a, 6); 
    push(&a, 5); 
    push(&a, 4); 
    push(&a, 3); 
    push(&a, 2); 
    push(&a, 1); 

    printList(a);

    push(&b, 8); 
    push(&b, 6); 
    push(&b, 4); 
    push(&b, 2); 

    printList(b);

    intersect = sortedIntersect(a, b);

    printList(intersect);

    return 0;
}