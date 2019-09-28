#include<iostream>
#include<queue>
#include<unordered_map>
#include<vector>

using namespace std;

struct compare { 
    bool operator()(pair<int, int> p1, pair<int, int> p2) { 
        // if frequencies of two elements are same 
        // then the larger number should come first 
        if (p1.second == p2.second) 
            return p1.first < p2.first; 
              
        // insert elements in the priority queue on the basis of 
        // decreasing order of frequencies     
        return p1.second < p2.second;     
    } 
};

void printNMostFrequent(int arr[], int n, int k){
    unordered_map<int, int> map;

    for(int i=0; i<n; i++){
        map[arr[i]]++;
    }

    priority_queue<pair<int, int>, vector<pair<int, int> >, compare> pQueue;

    for(auto x: map){
        pQueue.push(make_pair(x.first, x.second));
    }

    for(int i=0; i<k; i++){
        cout<<pQueue.top().first<<" ";
        pQueue.pop();
    }
    cout<<endl;
}

int main(){
    int arr[] = {3, 1, 4, 4, 5, 2, 6, 1};

    int n = sizeof(arr)/sizeof(arr[0]);

    int k = 2;

    printNMostFrequent(arr, n, k);

    return 0;
}