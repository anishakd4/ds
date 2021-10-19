#include<iostream>
#include<unordered_map>

using namespace std;

int findRepeating(int arr[], int n){
    unordered_map<int, int> myHash;
    for(int i=0; i<n; i++){
        if(myHash.find(arr[i]) != myHash.end()){
            return arr[i];
        }
        myHash[arr[i]] = 1;
    }
    return -1;
}

int main(){
    int arr[] = {9, 8, 2, 6, 1, 8, 5, 3, 4, 7 };
    int arr_size = sizeof(arr)/sizeof(arr[0]);
    cout<<findRepeating(arr, arr_size)<<endl;
    return 0;
}