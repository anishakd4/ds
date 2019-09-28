#include<iostream>

using namespace std;

int min(int a, int b, int c){
    int d = min(a, b);

    return min(d, c);
}

int getUglyNumber(int n){
    int ugly[n];

    int i2 =0 , i3 = 0, i5 =0;

    int next_multiple_2 = 2;
    int next_multiple_3 = 3;
    int next_multiple_5 = 5;

    ugly[0] = 1;

    for(int i=1; i<n; i++){
        int next_ugly_number = min(next_multiple_2, next_multiple_3, next_multiple_5);

        ugly[i] = next_ugly_number;

        if(next_ugly_number == next_multiple_2){
            i2++;
            next_multiple_2 = ugly[i2] * 2;
        }
        if(next_ugly_number == next_multiple_3){
            i3++;
            next_multiple_3 = ugly[i3] * 3;
        }
        if(next_ugly_number == next_multiple_5){
            i5++;
            next_multiple_5 = ugly[i5] * 5;
        }
    }

    return ugly[n-1];

}

int main(){

    int n = 150;

    int result = getUglyNumber(n);

    cout<<result<<endl;

    return 0;
}