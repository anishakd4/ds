#include<iostream>
#include<algorithm>

using namespace std;

struct Box{
    int h, w, d;
};

int min(int a, int b){
    return (a<b)?a:b;
}

int max(int a, int b){
    return (a>b)?a:b;
}

int compare (const void *a, const void * b) { 
    return ( (*(Box *)b).d * (*(Box *)b).w ) - 
           ( (*(Box *)a).d * (*(Box *)a).w ); 
}

int maxStackHeight(Box arr[], int n){
    Box rot[3*n];

    int j=0;

    for(int i=0; i<n; i++){
        rot[j].h = arr[i].h;
        rot[j].w = min(arr[i].w, arr[i].d);
        rot[j].d = max(arr[i].w, arr[i].d);
        j++;

        rot[j].h = arr[i].w;
        rot[j].w = min(arr[i].h, arr[i].d);
        rot[j].d = max(arr[i].h, arr[i].d);
        j++;

        rot[j].h = arr[i].d;
        rot[j].w = min(arr[i].w, arr[i].h);
        rot[j].d = max(arr[i].w, arr[i].h);
        j++;
    }

    qsort(rot, 3*n, sizeof(rot[0]), compare);

    int msh[3*n];

    for(int i=0; i<3*n; i++){
        msh[i] = rot[i].h;
    }

    for(int i=1; i<3*n; i++){
        for(int j=0; j<i; j++){
            if(rot[i].w < rot[j].w && rot[i].d < rot[j].d && msh[i] < msh[j] + rot[i].h){
                msh[i] = msh[j] + rot[i].h;
            }
        }
    }

    int max = msh[0];
    for(int i=1; i<3*n; i++){
        if(max < msh[i]){
            max = msh[i];
        }
    }

    return max;
}

int main(){

    Box arr[] = { {4, 6, 7}, {1, 2, 3}, {4, 5, 6}, {10, 12, 32} }; 
    int n = sizeof(arr)/sizeof(arr[0]);

    int result = maxStackHeight(arr, n);

    cout<<result<<endl;

    return 0;
}