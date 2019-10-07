#include<iostream>

using namespace std;

int maximum(int a, int b, int c) { 
   return max(max(a, b), c); 
} 
 
int minimum(int a, int b, int c) { 
   return min(min(a, b), c); 
} 

void smallestDifferenceTriplet(int arr1[], int arr2[], int arr3[], int n){

    sort(arr1, arr1 + n);
    sort(arr2, arr2 + n);
    sort(arr3, arr3 + n);

    int l, m, r;

    int i=0, j=0, k=0;

    int diff = INT_MAX;

    while(i < n && j < n && k < n){

        int sum = arr1[i] + arr2[j] + arr3[k];

        int max = maximum(arr1[i], arr2[j], arr3[k]);

        int min = minimum(arr1[i], arr2[j], arr3[k]); 

        if (min == arr1[i]){
            i++; 
        }else if (min == arr2[j]) {
            j++; 
        }else{
            k++;
        }

        if (diff > (max-min)) { 
            diff = max - min; 
            r = max; 
            m = sum - (max + min); 
            l = min; 
        }
    }

    cout<<r<< " , "<<m<<" , "<<l<<endl; 

}

int main(){

    int arr1[] = {5, 2, 8}; 
    int arr2[] = {10, 7, 12}; 
    int arr3[] = {9, 14, 6}; 

    int n = sizeof(arr1)/sizeof(arr1[0]);

    smallestDifferenceTriplet(arr1, arr2, arr3, n);

    return 0;
}