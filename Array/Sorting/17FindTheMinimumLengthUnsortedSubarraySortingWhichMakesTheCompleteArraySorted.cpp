#include<iostream>

using namespace std;

void printUnsorted(int arr[], int n){
    int s=0,e=n-1;

    for(s=0; s<n-1; s++){
        if(arr[s] > arr[s+1]){
            break;
        }
    }

    if (s == n-1) { 
        cout << "The complete array is sorted"; 
        return; 
    } 

    for(e=n-1; e>0; e--){
        if(arr[e] < arr[e-1]){
            break;
        }
    }

    int max = arr[s]; 
    int min = arr[s]; 
    for(int i = s + 1; i <= e; i++) { 
        if(arr[i] > max) {
            max = arr[i]; 
        }
        if(arr[i] < min) {
            min = arr[i]; 
        }
    } 

    for(int i = 0; i < s; i++) { 
        if(arr[i] > min) {  
            s = i; 
            break; 
        }      
    }  

    for(int i = n -1; i >= e+1; i--) { 
        if(arr[i] < max) { 
            e = i; 
            break; 
        }  
    } 

    cout<< s << " : " << e<<endl; 
}

int main(){

    int arr[] = {10, 12, 20, 30, 25, 40, 32, 31, 35, 50, 60};

    int n = sizeof(arr)/sizeof(arr[0]);

    printUnsorted(arr, n);

    return 0;
}