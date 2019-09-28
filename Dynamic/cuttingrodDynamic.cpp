#include<iostream>

using namespace std;

int max(int a, int b){
    return (a > b)? a:b;
}

int cutRod(int prices[], int n){

    int ans[n+1];

    ans[0]=0;

    for(int i=1; i<=n; i++){
        int min = prices[i-1];
        //cout<<min<<endl;
        for(int j=0; j<i; j++){
            min = max(prices[j]+ ans[i-j-1], min);
        }

        ans[i] = min;
    }

    return ans[n];
}

int main(){

    int arr[] = {1, 5, 8, 9, 10, 17, 17, 20};

    int n = sizeof(arr)/sizeof(arr[0]);

    int result = cutRod(arr, n);

    cout<<result<<endl;
    
    return 0;
}