#include<iostream>

using namespace std;

void printMaxActivities(int start[], int end[], int n){
    int i,j;

    i = 0;
    cout<<i<<"->";
    for(int j=1; j<n ; j++){
        if(start[j] >= end[i]){
            i = j;
            cout<<i<<"->";
        }
    }
    cout<<endl;
}

int main(){

    int start[] ={1, 3, 0, 5, 8, 5};
    int end[] = {2, 4, 6, 7, 9, 9};

    int n = sizeof(start)/sizeof(start[0]);

    printMaxActivities(start,end, n);
    return 0;
}