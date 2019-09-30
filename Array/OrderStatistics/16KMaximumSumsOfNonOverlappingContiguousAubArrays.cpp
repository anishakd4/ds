#include<iostream>

using namespace std;

int max(int a, int b){
    if(a>b){
        return a;
    }else{
        return b;
    }
}

void printArray(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void kMax(int arr[], int n, int k){
    for(int c=0; c<k; c++){
        int max_global = arr[0];
        int max_local = arr[0];

        int start =0, end = 0; 

        for(int i=1; i<n; i++){

            if(arr[i] == numeric_limits<int>::min()){
                max_local = arr[i];
            }else{
                if(arr[i] > (max_local + arr[i])){
                    max_local = arr[i];

                    if(max_global < max_local){
                        max_global = max_local;
                        start = i;
                        end = i;
                    }
                }else{
                    max_local = max_local + arr[i];
                    if(max_global < max_local){
                        max_global = max_local;
                        end = i;
                    }
                }
            }
            
            
            
        }

        cout<<"MAX sum: "<<max_global<<endl;
        cout<<"Start: "<<start<<endl;
        cout<<"End: "<<end<<endl;

        for (int i = start; i <= end; i++) {
            arr[i] = numeric_limits<int>::min();
        }

        printArray(arr, n);
    }
}

int main(){
    int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};

    int k = 3;

    int n = sizeof(arr)/sizeof(arr[0]);

    printArray(arr, n);

    kMax(arr, n, k);

    return 0;
}