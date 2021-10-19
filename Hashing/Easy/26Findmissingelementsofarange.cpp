#include<iostream>
#include<unordered_set>

using namespace std;

void printMissing(int arr[], int n, int low, int high){
    unordered_set<int> mySet;

    for(int i=0; i<n; i++){
        mySet.insert(arr[i]);
    }

    for(int x = low; x<=high; x++){
        if(mySet.find(x) == mySet.end()){
            cout<< x << " ";
        }
    }
    cout<<endl;
}

int main(){

    int arr[] = {1, 3, 5, 4 };
    int arr_size = sizeof(arr)/sizeof(arr_size);

    int low = 1, high = 10; 
    printMissing(arr, arr_size, low, high);

    return 0;
}