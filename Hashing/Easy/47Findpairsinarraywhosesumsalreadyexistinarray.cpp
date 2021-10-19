#include<iostream>
#include<unordered_set>

using namespace std;

void findPair(int arr[], int n){
    unordered_set<int> mySet;

    for(int i=0; i<n; i++){
        mySet.insert(arr[i]);
    }

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(mySet.find((arr[i] + arr[j])) != mySet.end()){
                cout<<arr[i] << " : " << arr[j]<<endl;
            }
        }
    }
}

int main(){

    int arr[] = {10, 4, 8, 13, 5};
    int arr_size = sizeof(arr)/sizeof(arr[0]);

    findPair(arr, arr_size);

    return 0;
}