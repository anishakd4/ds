#include<iostream>
#include<unordered_map>

using namespace std;

void groupElemets(int arr[], int n){
    unordered_map<int, int> myHash;

    for(int i=0; i<n; i++){
        myHash[arr[i]]++;
    }

    for(int i=0; i<n; i++){
        //cout<<myHash[arr[i]]<<endl;
        if(myHash.find(arr[i]) != myHash.end()){
            for(int j=0; j<myHash[arr[i]]; j++){
                cout<<arr[i]<<" ";
            }
            myHash[arr[i]] = 0;
        }
    }
    cout<<endl;
}

int main(){
    int arr[] = {10, 5, 3, 10, 10, 4, 1, 3};
    int arr_size = sizeof(arr)/sizeof(arr[0]);
    groupElemets(arr, arr_size);

    return 0;
}