#include<iostream>

using namespace std;

void findCommon(int ar1[], int ar2[], int ar3[], int n1, int n2, int n3){
    int i = 0, j = 0, k = 0; 

    while (i<n1 && j<n2 && k<n3){
        if (ar1[i] == ar2[j] && ar2[j] == ar3[k]){
            cout << ar1[i] << " ";   
            i++; j++; k++; 
        }else{
            if(ar1[i] <= ar2[j] && ar1[i] <= ar3[k]){
                i++;
            }else if(ar2[j] <= ar1[i] && ar2[j] <= ar3[k]){
                j++;
            }else{
                k++;
            } 
        }
    }
    cout<<endl;
}

int main(){

    int ar1[] = {1, 5, 5};
    int ar2[] = {3, 4, 5, 5, 10};
    int ar3[] = {5, 5, 10, 20};

    int n1 = sizeof(ar1)/sizeof(ar1[0]);
    int n2 = sizeof(ar2)/sizeof(ar2[0]);
    int n3 = sizeof(ar3)/sizeof(ar3[0]);

    // cout<<n1<<endl;
    // cout<<n2<<endl;
    // cout<<n3<<endl;

    findCommon(ar1, ar2, ar3, n1, n2, n3);

    return 0;
}