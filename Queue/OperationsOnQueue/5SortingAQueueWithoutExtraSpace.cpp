#include<iostream>
#include<queue>

using namespace std;

void printQueue(queue<int> q){
    cout<<"Queue: "<<endl;
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
}

int minIndex(queue<int> q, int x){
    int min_index = -1;
    int minValue = INT_MAX;
    for(int i=0; i<x; i++){
        int temp = q.front();
        q.pop();
        if(minValue > temp ) {
            min_index = i;
            minValue = temp;
        }
        q.push(temp);
    }

    return min_index;
}

void insertMinToRear(queue<int> &q, int  x){
    int minVal;
    int n = q.size();
    for(int i=0; i<n; i++){
        int temp = q.front();
        q.pop();
        if(i == x){
            minVal = temp;
        }else{
            q.push(temp);
        }
    }
    q.push(minVal);
}

void sortQueue(queue<int> &q){
    for(int i=0; i<q.size(); i++){
        int min_index = minIndex(q, q.size() - i); 
        insertMinToRear(q, min_index); 
    }
}

int main(){

    queue<int> q;

    q.push(30); 
    q.push(11); 
    q.push(15); 
    q.push(4); 

    printQueue(q);
    sortQueue(q);
    printQueue(q);

    return 0;
}