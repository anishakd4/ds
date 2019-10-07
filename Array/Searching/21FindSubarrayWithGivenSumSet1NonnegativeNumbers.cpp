#include<iostream>

using namespace std;

void printSolution(int arr[], int n, int sum){

    int currSum = arr[0];
    int start = 0;

    for(int i=1; i<n; i++){

        while (currSum > sum && start < i - 1){
            currSum = currSum - arr[start];
            start++;
        }
        
        if (currSum == sum) {  
            cout << "Sum found between indexes " << start << " and " << i - 1<<endl; 
            return; 
        }

        currSum = currSum + arr[i];

    }
    cout << "No subarray found"<<endl;
}

int main(){

    int arr[] = {15, 2, 4, 8, 9, 5, 10, 23};

    int n = sizeof(arr)/sizeof(arr[0]);

    int sum = 23;

    printSolution(arr, n, sum);

    return 0;
}