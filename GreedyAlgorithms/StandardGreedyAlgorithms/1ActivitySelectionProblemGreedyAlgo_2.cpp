#include<iostream>
#include<algorithm>

using namespace std;

struct Activity{
    int start;
    int end;
};

bool activityCompare(Activity a1, Activity a2){
    return a1.end < a2.end;
}

void printMaxActivities(Activity arr[], int n){
    sort(arr, arr+n, activityCompare);

    int i, j;
    i=0;
    cout<<arr[i].start<<" : "<<arr[i].end<<endl;

    for(int j=1; j<n; j++){
        if(arr[j].start > arr[i].end){
            i = j;
            cout<<arr[i].start<<" : "<<arr[i].end<<endl;
        }
    }
}

int main(){

    Activity arr[] = {{5, 9}, {1, 2}, {3, 4}, {0, 6}, {5, 7}, {8, 9}}; 

    int n = sizeof(arr)/sizeof(arr[0]);
    printMaxActivities(arr, n);

    return 0;
}