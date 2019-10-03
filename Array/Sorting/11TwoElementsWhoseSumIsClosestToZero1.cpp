#include<iostream>

using namespace std;

void minAbsSumPair(int arr[], int n){

    int l = 0, r = n-1, min_l=0, min_r=n-1, min=INT_MAX;

    sort(arr, arr+n);

    while (l<r){
        int temp = arr[l] + arr[r];
        if(abs(temp) < min){
            min = temp;
            min_l = l;
            min_r = r;
        }
        if(temp == 0){
            break;
        }else if(temp < 0){
            l++;
        }else{
            r--;
        }
    }

    cout << "The two elements whose sum is minimum are " << arr[min_l] << " and " << arr[min_r]<<endl;
    
}

int main(){

    int arr[] = {1, 60, -10, 70, -80, 85};

    int n = sizeof(arr)/sizeof(arr[0]);

    minAbsSumPair(arr, n);

    return 0;
}