#include<iostream>
#define MAX 10000
using namespace std;

int countPairs(int arr[], int n, int k){
    int count = 0; 

    bool hashmap[MAX] = {false}; 
  
    for (int i = 0; i < n; i++) {
        hashmap[arr[i]] = true; 
    }
  
    for (int i = 0; i < n; i++) { 
        int x = arr[i]; 
        if (x - k >= 0 && hashmap[x - k]){
            count++;
        }
        if (x + k < MAX && hashmap[x + k]) {
            count++; 
        }
        hashmap[x] = false; 
    } 
    return count;
}

int main(){
    int arr[] = {1, 5, 3, 4, 2};

    int n = sizeof(arr)/sizeof(arr[0]);

    int k=3;

    int answer = countPairs(arr, n, k);

    cout<<answer<<endl;

    return 0;
}