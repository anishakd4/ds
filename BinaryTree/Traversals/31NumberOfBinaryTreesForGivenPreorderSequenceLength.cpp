#include<iostream>

using namespace std;

int countTrees(int n){
    int bt[n+1];
    memset(bt, 0, sizeof(bt)); 

    bt[0] = bt[1] = 1;

    for(int i=2; i<=n; i++){
        for(int j=0; j<i; j++){
            bt[i] = bt[i] + bt[j] * bt[i-j-1];
        }
    }

    return bt[n];
}

int main(){
    int n = 5; 
    cout << "Total Possible Binary Trees are : " << countTrees(n) << endl;

    return 0;
}