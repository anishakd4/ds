#include<iostream>
#include<cmath>

using namespace std;

int fact(int n){  
    return (n == 0)? 1 : n*fact(n-1);  
} 

void printRepeating(int arr[], int n){
    int S = 0; 
    int P = 1;
    int x, y;
    int D;
    int i;  
      
    /* Calculate Sum and Product of all elements in arr[] */
    for(i = 0; i < n; i++)  {  
        S = S + arr[i];  
        P = P*arr[i];  
    }   

    n=n-2;

    S = S - n*(n+1)/2;
    P = P/fact(n); 

    D = sqrt(S*S - 4*P);

    x = (D + S)/2;  
    y = (S - D)/2;

    cout<<x<<endl;
    cout<<y<<endl;
}

int main(){

    int arr[] = {4, 2, 4, 5, 2, 3, 1};

    int n = sizeof(arr)/sizeof(arr[0]);

    printRepeating(arr, n);

    return 0;
}