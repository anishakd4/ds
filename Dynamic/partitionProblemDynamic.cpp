#include<iostream>

using namespace std;

bool checkPartition(int arr[], int n){
    int sum=0;

    for(int i=0; i<n; i++){
        sum = sum + arr[i]; 
    }

    if(sum %2 != 0){
        return false;
    }

    bool part[sum/2 + 1][n+1];

    for(int i=0; i<=n; i++){
        part[0][i] = true;
    }

    for(int i=1; i<=sum/2; i++){
        part[i][0] = false;
    }

    for(int i=1; i<=sum/2; i++){
        for(int j=1; j<=n; j++){
            part[i][j] = part[i][j-1];
            if(i >= arr[j-1]){
                part[i][j] = part[i][j-1] || part[i - arr[j-1]][j-1];
            }
        }
    }

    return part[sum/2][n];
}

int main(){
    int arr[] = {3, 1, 5, 9, 12};  

    int n = sizeof(arr)/sizeof(arr[0]);

    bool result = checkPartition(arr, n);

    if(result){
        cout<<"true"<<endl;
    }else{
        cout<<"false"<<endl;
    }

    return 0;
}