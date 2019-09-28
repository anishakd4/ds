#include<iostream>

using namespace std;

int maxDivide(int n, int d){
    while(n%d == 0){
        n = n/d;
    }

    return n;
}

bool isUgly(int n){
    n = maxDivide(n, 2);
    n = maxDivide(n, 3);
    n = maxDivide(n, 5);

    return (n == 1)? true: false;

}

int getUgly(int n){

    int i=1;
    int count = 1;

    while(n > count){
        i++;
        cout<<i<<endl;

        if(isUgly(i)){
            count++;
        }
    }

    return i;
}

int main(){

    int n =150;

    int result = getUgly(n);

    cout<<result<<endl;

    return 0;
}