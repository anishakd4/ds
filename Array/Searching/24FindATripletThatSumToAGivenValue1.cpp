#include<iostream>

using namespace std;

void find3Numbers(int arr[], int n, int sum){
    int l, r;

    sort(arr, arr+n);

    for(int i=0; i<n-2; i++){

        l = i+1;
        r = n-1;

        while(l < r){
            if(arr[i] + arr[l] + arr[r] == sum){
                cout<<arr[i]<<" : "<<arr[l]<<" : "<<arr[r]<<endl;
                return;
            }else if(arr[i] + arr[l] + arr[r] < sum){
                l++;
            }else{
                r--;
            }
        }
    }
    cout<<"No triplet found"<<endl;
}

int main(){

    int arr[] = {1, 4, 45, 6, 10, 8 };

    int sum = 22;

    int n = sizeof(arr)/sizeof(arr[0]);

    find3Numbers(arr, n, sum);

    return 0;
}