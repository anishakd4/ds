#include<iostream>
#include<unordered_map>

using namespace std;


int findMajority(int arr[], int n){
    unordered_map<int, int> map;

    for(int i=0; i<n; i++){
        map[arr[i]]++;
    }

    for(auto m: map){
        if(m.second > n/2){
            return m.first;
        }
    }

    return -1;
}

int main(){

    int arr[] = {2, 2, 2, 2, 5, 5, 2, 3, 3};

    int n = sizeof(arr)/sizeof(arr[0]);

    int answer = findMajority(arr, n);

    cout<<answer<<endl;

    return 0;
}