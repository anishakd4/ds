#include<iostream>
#include<queue>

using namespace std;

void reverseQueue(queue<long long int> &q){
    if(q.empty()){
        return;
    }
    int s= q.size();

    long long int data = q.front(); 
    q.pop(); 
   
    reverseQueue(q); 
    
    q.push(data); 
}

void printQueue(queue<long long int> q){
    cout<<"Queue: "<<endl;
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
}

int main(){

    queue<long long int> Queue; 

    Queue.push(56); 
    Queue.push(27); 
    Queue.push(30); 
    Queue.push(45); 
    Queue.push(85); 
    Queue.push(92); 
    Queue.push(58); 
    Queue.push(80); 
    Queue.push(90); 
    Queue.push(100); 

    printQueue(Queue); 
    reverseQueue(Queue); 
    printQueue(Queue); 

    return 0;
}