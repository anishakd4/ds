#include<iostream>

using namespace std;

int getCount(int arr[], int n){
    int answer = 0;

    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(arr[i] > arr[j]){
                answer = answer + 1;
            }
        }
    }

    return answer;
}

int main(){
    int arr[] = {1, 20, 6, 4, 5};

    int n = sizeof(arr)/sizeof(arr[0]);

    int answer = getCount(arr, n);

    cout<<answer<<endl;

    return 0;
}