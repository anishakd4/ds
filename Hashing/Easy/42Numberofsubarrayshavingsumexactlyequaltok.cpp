#include<iostream>
#include<unordered_map>

using namespace std;

int findSubarraySum(int arr[], int n, int sum){

    unordered_map<int, int> myMap;

    int currSum = 0;
    int res = 0;

    for(int i=0; i<n; i++){
        currSum = currSum + arr[i];

        if(currSum == sum){
            res++;
        }

        if(myMap.find(currSum - sum) != myMap.end()){
            res = res + myMap[currSum - sum];
        }

        myMap[currSum]++;
    }

    return res;
}

int main(){

    int arr[] = {10, 2, -2, -20, 10};
    int sum = -10; 
    int arr_size = sizeof(arr)/sizeof(arr[0]);

    cout << findSubarraySum(arr, arr_size, sum) <<endl;
    return 0;
}