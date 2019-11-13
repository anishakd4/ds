#include<iostream>

using namespace std;

struct Node{
    int data;
    int prioriy;
    struct Node* next;
};

Node* newNode(int d, int p){
    Node* temp = new Node;
    temp->data = d;
    temp->prioriy = p;
    temp->next = NULL;

    return temp;
}

bool isEmpty(Node* head){
    return (head == NULL);
}

int peek(Node* head){
    return head->data;
}

void pop(Node** head){
    Node* temp = *head;
    (*head) = (*head)->next;
    free(temp);
}

void push(Node** head, int d, int p){
    struct Node* new_node = newNode(d, p);
    if((*head)->prioriy > p){
        new_node->next = *head;
        *head = new_node;
    }else{
        struct Node* start = *head;
        while(start->next != NULL && start->next->prioriy < p){
            start = start->next;
        }
        new_node->next = start->next;
        start->next = new_node;
    }
}

int main(){

    Node* pq = newNode(4, 1); 
    push(&pq, 5, 2); 
    push(&pq, 6, 3); 
    push(&pq, 7, 0); 
  
    while (!isEmpty(pq)) { 
        printf("%d ", peek(pq)); 
        pop(&pq); 
    } 

    return 0;
}