#include<iostream>

using namespace std;

int max(int a, int b){
    return (a > b)? a : b;
}

int knapSack(int val[], int wt[], int n, int W){
    if(n == 0 || W == 0){
        return 0;
    }

    if(wt[n-1] > W){
        return knapSack(val, wt, n-1, W);
    }

    return max(knapSack(val, wt, n-1, W), val[n-1] + knapSack(val, wt, n-1, W-wt[n-1]));

}

int main(){
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int W = 50;

    int n = sizeof(val)/sizeof(val[0]);

    int result =  knapSack(val, wt, n , W);
    cout<<result<<endl;

    return 0;
}