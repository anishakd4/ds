#include<iostream>

using namespace std;

int maxSumTriplet(int arr[], int n){

    int maxA = INT_MIN; 
    int maxB = INT_MIN; 
    int maxC = INT_MIN; 

    for(int i=0; i<n; i++){
        if(arr[i] > maxA){
            maxA = arr[i];
            maxB = maxA;
            maxC = maxB;
        }else if(arr[i]> maxB){
            maxB = arr[i];
            maxC = maxB;
        }else if (arr[i] > maxC) {
            maxC = arr[i]; 
        }
    }

    return (maxA + maxB + maxC);
}

int main(){

    int arr[] = {1, 0, 8, 6, 4, 2 };

    int n = sizeof(arr)/sizeof(arr[0]);

    int answer = maxSumTriplet(arr, n);

    cout<<answer<<endl;

    return 0;
}