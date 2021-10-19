#include<iostream>
#include<unordered_map>

using namespace std;

int minDelete(int arr[], int n){

    unordered_map<int, int> m;
    for(int i=0; i<n; i++){
        m[arr[i]]++;
    }

    int max_freq = INT_MIN;
    unordered_map<int, int> :: iterator it;
    for(it = m.begin(); it != m.end(); it++){
        max_freq = max(max_freq, it->second);
    }

    return n-max_freq;
}

int main(){

    int arr[] = {4, 3, 4, 4, 2, 4};

    int arr_size = sizeof(arr)/sizeof(arr_size);

    cout<<minDelete(arr, arr_size) <<endl;
    return 0;
}