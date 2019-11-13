#include<iostream>

using namespace std;

struct Node{
    int data;
    struct Node* next;
};

struct Queue{
    struct Node *front, *rear;
};

void enqueue(Queue *q, int value){
    struct Node* temp = new Node;
    temp->data = value;
    if(q->front == NULL){
        q->front = temp;
    }else{
        q->rear->next = temp;
    }

    q->rear = temp;
    q->rear->next = q->front;
}

int dequeue(Queue *q){
    if(q->front == NULL){
        cout<<"Queue empty: "<<endl;
        return -1;
    }

    int value;
    if(q->front == q->rear){
        value = q->front->data;
        free(q->front);
        q->front = NULL;
        q->rear = NULL;
    }else{
        struct Node* temp = q->front;
        value = temp->data;
        q->front = q->front->next;
        q->rear->next = q->front;
        free(temp);
    }

    return value;
}

void displayQueue(struct Queue *q){
    cout<<"Queue: "<<endl;
    struct Node* temp = q->front;
    while (temp->next != q->front){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<temp->data<<endl;
}

int main(){

    Queue *q;
    q->front = q->rear = NULL;

    enqueue(q, 14); 
    enqueue(q, 22); 
    enqueue(q, 6); 
  
    displayQueue(q); 
  
    printf("Deleted value = %d\n", dequeue(q)); 
    printf("Deleted value = %d\n", dequeue(q)); 
  
    displayQueue(q); 
  
    enqueue(q, 9); 
    enqueue(q, 20);

    displayQueue(q); 

    return 0;
}