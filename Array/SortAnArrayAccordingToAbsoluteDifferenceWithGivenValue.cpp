#include<iostream>
#include <map> 

using namespace std;

void printArray(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void sortX(int arr[], int n, int x){
    multimap<int,int> map;
    multimap<int ,int>:: iterator it; 


    for(int i=0; i<n; i++){
        map.insert(make_pair(abs(x-arr[i]), arr[i]));
    }

    int i=0;
    for(it=map.begin(); it!= map.end(); it++){
        arr[i] = (*it).second;
        i++;
    }
}

int main(){

    int arr[] = {10, 5, 3, 9 ,2};

    int n = sizeof(arr)/sizeof(arr[0]);

    int x=7;

    sortX(arr, n, x);
    printArray(arr, n);

    return 0;
}