#include<iostream>
#include<unordered_map>
#include<cmath>

using namespace std;

void printUnorderedMap(unordered_map<int, int> cnt){
    for(auto x : cnt){
        cout<<x.first<<" : "<<x.second<<endl;
    }
}

void printArray(int arr[], int n){
    for (int i = 0; i < n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void printSegmentTree(int *st, int n){
    for(int i=0; i<n; i++){
        cout<<st[i]<<" ";
    }
    cout<<endl;
}

int constructSegmentTreeUtil(int arr[], int ss, int se, int *st, int treeNode){
    if(ss == se){
        st[treeNode] = arr[ss];
        return arr[ss];
    }

    int mid = (ss + se)/2;
    st[treeNode] = max(constructSegmentTreeUtil(arr, ss, mid, st, 2*treeNode+1), constructSegmentTreeUtil(arr, mid+1, se, st, 2*treeNode+2));
    return st[treeNode];
}

int* constructSegmentTree(int freq_arr[], int n){
    int height = ceil(log2(n));
    int max_size = 2 * pow(2, height) - 1;
    int *st = new int[max_size];
    constructSegmentTreeUtil(freq_arr, 0, n-1, st, 0);
    printSegmentTree(st, max_size);
    return st;
}

int maximumOccurrence(int arr[], int n, int qs, int qe){
    int freq_arr[n]; 
  
    unordered_map<int, int> cnt;

    for (int i = 0; i < n; i++){
        cnt[arr[i]]++;  
    }

    printUnorderedMap(cnt);

    for (int i = 0; i < n; i++) {
        freq_arr[i] = cnt[arr[i]]; 
    }

    printArray(freq_arr, n);

    int* st = constructSegmentTree(freq_arr, n);

    int maxOcc;

    if (arr[qs] == arr[qe]){
        maxOcc = (qe - qs + 1); 
    }else{
        
    }

    return maxOcc;
}

int main(){

    int arr[] = {-5, -5, 2, 2, 2, 2, 3, 7, 7, 7};

    int n = sizeof(arr)/sizeof(arr[0]);

    int qs = 0;
    int qe = 9; 

    int answer = maximumOccurrence(arr, n, qs, qe);
  
    cout << "Maximum Occurrence in range is = " << answer << endl; 
  
    qs = 4;
    qe = 9;

    answer = maximumOccurrence(arr, n, qs, qe);
  
    cout << "Maximum Occurrence in range is = " << answer << endl; 

    return 0;
}