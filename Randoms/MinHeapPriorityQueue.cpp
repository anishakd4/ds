#include<iostream>
#include<queue>

using namespace std;

void printQueue(priority_queue<int, vector<int>, greater<int> > pQueue){
    priority_queue<int, vector<int>, greater<int> > x = pQueue;
    while (!x.empty()){
        cout<<x.top()<<" ";
        x.pop();
    }
    cout<<endl;
}

int main(){
    priority_queue<int, vector<int>, greater<int> > pQueue;

    pQueue.push(10);
    printQueue(pQueue);
    pQueue.push(30);
    printQueue(pQueue);
    pQueue.push(20);
    printQueue(pQueue);
    pQueue.push(5);
    printQueue(pQueue);
    pQueue.push(1);
    printQueue(pQueue);

    cout<<pQueue.size()<<endl;
    cout<<pQueue.top()<<endl;

    pQueue.pop();
    printQueue(pQueue);
}