#include<iostream>
#include<unordered_set>

using namespace std;

void find3Numbers(int arr[], int n, int sum){
    for(int i=0; i<n-2; i++){

        unordered_set<int> set;
        int currSum = sum - arr[i];

        for(int j=i+1; j<n; j++){

            if(set.find(currSum  - arr[j]) != set.end()){
                cout<<arr[i]<<" : "<<arr[j]<<" : "<<currSum  - arr[j]<<endl;
            }
            set.insert(arr[j]);
        }
    }
}

int main(){

    int arr[] = {1, 4, 45, 6, 10, 8};

    int n = sizeof(arr)/sizeof(arr[0]);

    int sum = 22; 

    find3Numbers(arr, n, sum);

    return 0;
}