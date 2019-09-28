#include<iostream>
#include<algorithm>

using namespace std;

int lis(int arr[], int n){
    int li[n];

    li[0] = 1;

    for(int i=1; i<n; i++){
        li[i] = 1;

        for(int j=0; j<i; j++){
            if(arr[i]>arr[j] && li[i] < li[j] + 1){
                li[i] = li[j] + 1;
            }
        }
    }

    return *max_element(li, li+n);;
}

int main(){
    int arr[] = {50, 3, 10, 7, 40, 80};  
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<n<<endl;
    int result = lis(arr, n);
    cout<<result<<endl;
    return 0;
}