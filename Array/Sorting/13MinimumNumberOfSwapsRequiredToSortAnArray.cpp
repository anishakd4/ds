#include<iostream>
#include<vector>

using namespace std;

void printArray(pair<int, int> arrPos[], int n){
    for(int i=0; i<n; i++){
        cout<<arrPos[i].first<<" "<<arrPos[i].second<<endl;
    }
    cout<<endl;
}

int minswaps(int arr[], int n){

    pair<int, int> arrPos[n];

    for(int i=0; i<n; i++){
        arrPos[i].first = arr[i];
        arrPos[i].second = i;
    }

    printArray(arrPos, n);

    sort(arrPos, arrPos + n);

    printArray(arrPos, n);

    vector<bool> vis(n, false);

    int answer = 0;

    for(int i = 0; i < n; i++){
        if(arrPos[i].second == i || vis[i]){
            continue;
        }

        int cycleSize = 0;
        int j=i;

        while (!vis[j]){
            cout<<j<<" - ";
            vis[j] = 1;

            j = arrPos[j].second;
            cycleSize++;
        }

        cout<<endl;
        
        if(cycleSize > 0){
            answer += (cycleSize-1);
        }
    }
    

    return answer;

}

int main(){

    int arr[] = {1, 5, 4, 3, 2};

    int n = sizeof(arr)/sizeof(arr[0]);

    int answer = minswaps(arr, n);

    cout<<answer<<endl;

    return 0;
}