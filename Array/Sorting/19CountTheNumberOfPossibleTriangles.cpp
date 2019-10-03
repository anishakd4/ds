#include<iostream>
#include<algorithm>

using namespace std;

int findNumberOfTriangles(int arr[], int n){
    sort(arr, arr+n);

    int count = 0;

    for(int i=0; i<n-2; i++){

        int k = i+2;
        for(int j=i+1; j<n; j++){
            while (k < n && arr[i] + arr[j] > arr[k]) {
                k++;
            }
            if(k > j){
                count += k - j - 1; 
            }
        }
    }


    return count;
}

int main(){

    int arr[] = {10, 21, 22, 100, 101, 200, 300};

    int n = sizeof(arr)/sizeof(arr[0]);

    int answer = findNumberOfTriangles(arr, n);

    cout<<answer<<endl;

    return 0;
}