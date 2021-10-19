#include<iostream>
#include<unordered_map>

using namespace std;

int findGreatest(int arr[], int n){

    unordered_map<int, int> mySet;
    for(int i=0; i<n; i++){
        mySet[arr[i]]++;
    }

    sort(arr, arr+n);

    for(int i=n-1; i>1; i++){
        for (int j=0; j<i && arr[j]<=sqrt(arr[i]); j++) {
            if(arr[i] % arr[j] == 0){
                int result = arr[i]/arr[j];
                if(result != arr[j] && mySet.find(arr[j]) != mySet.end()){
                    return arr[i];
                }else if(result == arr[j] && mySet[arr[j]] > 1){
                    return arr[i];
                }
            }
        }
    }

    return -1;
}


int main(){
    int arr[] = {17, 2, 1, 15, 30}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
  
    cout << findGreatest(arr, n) <<endl; 
    return 0;
}