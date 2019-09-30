#include <iostream> 
#include <queue>
using namespace std;


int minProduct(int arr[], int n, int k){
    priority_queue<int, vector<int>, greater<int> > pQueue;

    for(int i=0; i<n; i++){
        pQueue.push(arr[i]);
    }

    int count=0;
    int answer = 1;

    while (!pQueue.empty() && count<k){
        answer = answer * pQueue.top();
        pQueue.pop();
        count++;
    }
    
    return answer;
}

int main(){
    int arr[] = {198, 76, 544, 123, 154, 675};

    int k = 2;

    int n = sizeof(arr)/sizeof(arr[0]);

    int answer = minProduct(arr, n, k);

    cout<<answer<<endl;

    return 0;
}