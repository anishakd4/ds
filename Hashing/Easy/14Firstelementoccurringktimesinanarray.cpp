#include<iostream>
#include<unordered_map>
using namespace std;

void firstElement(int arr[], int n, int k){
    unordered_map<int, int> myHash;

    for(int i=0; i<n; i++){
        myHash[arr[i]]++;
        if(myHash[arr[i]] == k){
            cout<<arr[i]<<endl;
            return;
        }
    }

}

int main(){
    int arr[] = {1, 7, 4, 3, 4, 8, 7};
    int arr_size = sizeof(arr)/sizeof(arr[0]);
    int k = 2; 
    firstElement(arr, arr_size, k);
    return 0;
}