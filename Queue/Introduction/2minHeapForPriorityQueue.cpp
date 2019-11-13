#include<iostream>
#include<queue>

using namespace std;

void printPriorityQueue(priority_queue<int, vector<int>, greater<int> > pq){
    cout<<"Priority Queue: "<<endl;
    while (!pq.empty()){
        cout<<pq.top()<<" ";
        pq.pop();
    }
    cout<<endl;
}

int main(){
    priority_queue<int, vector<int>, greater<int> > pq;

    pq.push(10); 
    pq.push(30); 
    pq.push(20); 
    pq.push(5); 
    pq.push(1);

    printPriorityQueue(pq); 
  
    cout << "size() : " << pq.size()<<endl;; 
    cout << "top() : " << pq.top()<<endl; 
  
    cout << ".pop() : "<<endl; 
    pq.pop(); 

    printPriorityQueue(pq); 

    return 0;
}