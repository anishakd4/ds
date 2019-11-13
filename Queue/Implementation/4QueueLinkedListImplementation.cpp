#include<iostream>

using namespace std;

class QueueNode{
    public:
        int data;
        QueueNode* next;
};

class Queue{
    public:
        QueueNode *front, *rear;
};

Queue* createQueue(){
    Queue* q;
    q->front=q->rear=NULL;
    return q;
}

QueueNode* newNode(int x){
    QueueNode* new_node = new QueueNode();
    new_node->data = x;
    new_node->next = NULL;
    return new_node;
}

void enqueue(Queue* q, int x){
    QueueNode* new_node = newNode(x);
    if(q->rear == NULL){
        q->front=q->rear=new_node;
        return;
    }
    q->rear->next = new_node;
    q->rear=new_node;
}

QueueNode* dequeue(Queue* q){
    if(q->front == NULL){
        return NULL;
    }

    QueueNode* temp = q->front;
    q->front = q->front->next;

    if(q->front == NULL){
        q->rear = NULL;
    }

    return temp;
}

int main(){
    Queue* q = createQueue();
    
    enqueue(q, 10); 
    enqueue(q, 20); 
    dequeue(q); 
    dequeue(q); 
    enqueue(q, 30); 
    enqueue(q, 40); 
    enqueue(q, 50); 

    QueueNode* qn = dequeue(q);
    if(qn != NULL){
        cout << "Dequeued item is " << qn->data<<endl;
    }

    return 0;
}