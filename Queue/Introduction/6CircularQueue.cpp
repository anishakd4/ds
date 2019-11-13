#include<iostream>

using namespace std;

struct CircularQueue{
    int front, rear, size, length;
    int *arr;

    CircularQueue(int s){
        front = rear = -1;
        size = s;
        length = 0;
        arr = new int[s];
    }

    void enqueue(int x);
    int dequeue();
    void displayQueue();
    bool isFull();
    bool isEmpty();
};

bool CircularQueue::isFull(){
    if(length == size){
        return true;
    }
    return false;
}

bool CircularQueue::isEmpty(){
    if(length == 0){
        return true;
    }
    return false;
}

void CircularQueue::enqueue(int x){
    if(isFull()){
        cout<<"Queue is full"<<endl;
    }else if(front == -1){
        rear = front = 0;
        arr[rear] = x;
        length++;
    }else{
        rear = (rear + 1) % (size);
        arr[rear] = x;
        length++;
    }

    cout<<"enqueue front: "<<front<<" enqueue rear: "<<rear<<endl;
}

int CircularQueue::dequeue(){
    if(isEmpty()){
        cout<<"Queue is empty"<<endl;
        return -1;
    }

    int temp = arr[front];
    if (front == rear) { 
        front = -1; 
        rear = -1; 
    }else{
        front = (front + 1) % (size);
    }
    length--;

    cout<<"dequeue front: "<<front<<" dequeue rear: "<<rear<<endl;

    return temp;
}

void CircularQueue::displayQueue(){
    if(isEmpty()){
        cout<<"Queue is empty"<<endl;
    }else{
        cout<<"Queue: "<<endl;
        int i=front;
        int j=rear;
        while(i != j){
            cout<<arr[i]<<" ";
            i = (i+1) % (size);
        }
        cout<<arr[i]<<endl;
    }
    cout<<"displayQueue front: "<<front<<" displayQueue rear: "<<rear<<endl;
}

int main(){

    CircularQueue q(5);

    q.enqueue(14); 
    q.enqueue(22); 
    q.enqueue(13); 
    q.enqueue(-6);

    q.displayQueue(); 

    printf("Deleted value = %d\n", q.dequeue()); 
    printf("Deleted value = %d\n", q.dequeue()); 
  
    q.displayQueue(); 
  
    q.enqueue(9); 
    q.enqueue(20); 
    q.enqueue(5); 
  
    q.displayQueue(); 
  
    q.enqueue(20);

    q.displayQueue(); 

    return 0;
}