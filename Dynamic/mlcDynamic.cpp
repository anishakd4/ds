#include<iostream>

using namespace std;

struct pairr{
    int a;
    int b;
};

int max(int a, int b){
    return (a>b)?a:b;
}

int maxChainLength(struct pairr arr[], int n){
    int mcl[n];

    for(int i=0; i<n; i++){
        mcl[i] = 1;
    }

    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++){
            if(arr[i].a > arr[j].b && mcl[i] < mcl[j] + 1){
                mcl[i] = mcl[j] + 1;
            }
        }
    }

    int result = mcl[0];

    for(int i=1; i<n; i++){
        result = max(result, mcl[i]);
    }
    return result;
}

int main(){

    struct pairr arr[] = { {5, 24}, {15, 25}, {27, 40}, {50, 60}};

    int n= sizeof(arr)/sizeof(arr[0]);

    int result = maxChainLength(arr, n);

    cout<<result<<endl;

    return 0;
}