#include<iostream>

using namespace std;

int count(int x, int y[], int n, int NofY[]){
    if( x == 0){
        return 0;
    }

    if(x == 1){
        return NofY[0];
    }

    int* idx = upper_bound(y, y + n, x); 

    int ans = (y + n) - idx; 

    ans += (NofY[0] + NofY[1]);

    if (x == 2)  {
        ans -= (NofY[3] + NofY[4]); 
    }

    if (x == 3)  {
        ans += NofY[2]; 
    }

    return ans;
}

int countPairs(int x[], int y[], int m , int n){
    int NofY[5] = {0};

    for(int i=0; i<n; i++){
        if(y[i] < 5){
            NofY[y[i]]++;
        }
    }

    sort(y, y+n);

    int total_pairs = 0;

    for(int i=0; i<m; i++){
        total_pairs = total_pairs + count(x[i], y, n, NofY);
    }

    return total_pairs;
}

int main(){

    int x[] = {2, 1, 6}; 
    int y[] = {1, 5};

    int m = sizeof(x)/sizeof(x[0]);

    int n = sizeof(y)/sizeof(y[0]);

    int answer = countPairs(x, y, m, n);

    cout<<answer<<endl;

    return 0;   
}