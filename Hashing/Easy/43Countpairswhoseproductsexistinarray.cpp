#include<iostream>
#include<unordered_set>

using namespace std;

int countPairs(int arr[], int n){
    unordered_set<int> myset;
    int count = 0;

    for(int i=0; i<n; i++){
        myset.insert(arr[i]);
    }

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(myset.find(arr[i] * arr[j]) != myset.end()){
                count++;
            }
        }
    }

    return count;
}

int main(){
    int arr[] = {6 ,2 ,4 ,12 ,5 ,3};
    int arr_size = sizeof(arr)/sizeof(arr[0]);

    cout<<countPairs(arr, arr_size)<<endl;
    return 0;
}