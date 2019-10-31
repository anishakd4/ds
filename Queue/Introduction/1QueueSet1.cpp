#include<iostream>

using namespace std;

class Queue{
    public:
        int front, rear, size;
        int* array;
        unsigned capacity;
};

Queue* createQueue(unsigned capacity){
    Queue* q = new Queue();
    q->capacity = capacity;
    q->front = q->size = 0;
    q->rear=capacity-1;
    q->array = new int[(q->capacity * sizeof(int) )];
    return q;
}

bool isFull(Queue* q){
    return (q->size == q->capacity);
}

bool isEmpty(Queue* q){
    return (q->size == 0);
}

void enqueue(Queue* q, int item){
    if(isFull(q)){
        return;
    }
    q->rear = (q->rear + 1) % q->capacity;
    q->array[q->rear] = item;
    q->size = q->size + 1;
    cout << item << " enqueued to queue"<<endl;
}

int dequeue(Queue* q){
    if(isEmpty(q)){
        return -1;
    }

    int item = q->array[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size = q->size - 1;
    return item;
}

int front(Queue* q){
    if(isEmpty(q)){
        return -1;
    }
    return q->array[q->front];
}

int rear(Queue* q){
    if(isEmpty(q)){
        return -1;
    }
    return q->array[q->rear];
}

int main(){

    Queue* q = createQueue(100);

    enqueue(q, 10);  
    enqueue(q, 20);  
    enqueue(q, 30);  
    enqueue(q, 40); 

    cout<<dequeue(q)<<" dequeued from queue\n";  
  
    cout << "Front item is " << front(q) << endl;  
    cout << "Rear item is " << rear(q) << endl;  

    return 0;
}