#include<iostream>
#include<unordered_map>

using namespace std;

int findRepeatingNumber(int arr[], int arr_size){
    unordered_map<int, int> myHash;

    for(int i=0; i<arr_size; i++){
        if(myHash.find(arr[i]) != myHash.end()){
            return arr[i];
        }else{
            myHash[arr[i]] = 1;
        }
    }

    return -1;
}

int main(){
    int arr[] = {1, 1, 2, 3, 5, 4};

    int arr_size = sizeof(arr)/sizeof(arr[0]);

    int n = 5;

    cout<<findRepeatingNumber(arr, arr_size)<<endl;
    return 0;
}