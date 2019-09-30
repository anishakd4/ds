#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int queryRec(int ss, int se,  int qs, int qe, int treeIndex, int k, vector<int> segmentTree[]){
    if(ss == se){
        return segmentTree[treeIndex][0];
    }

    int mid = (ss + se)/2;

    int last_in_query_range = upper_bound(segmentTree[2*treeIndex +1].begin(), segmentTree[2*treeIndex +1].end(), qe) - segmentTree[2*treeIndex + 1].begin();  

    int first_in_query_range = lower_bound(segmentTree[2*treeIndex +1].begin(), segmentTree[2*treeIndex +1].end(), qs) - segmentTree[2*treeIndex + 1].begin(); 

    int m = last_in_query_range - first_in_query_range;

    if(m >= k){
        return queryRec(ss, mid, qs, qe, (2*treeIndex + 1), k, segmentTree); 
    }else{
        return queryRec((mid + 1), se, qs, qe, (2*treeIndex + 2), (k - m), segmentTree); 
    }
    
}

int query(int queryStart, int queryEnd, int K, int n, vector<int> segmentTree[]) {
    return queryRec(0, n - 1, queryStart-1, queryEnd-1,  0, K, segmentTree); 
}

void printSegmentTree(vector<int> segmentTree[], int n){

    for(int i=0; i<n; i++){
        for(int j=0; j<segmentTree[i].size(); j++){
            cout<<segmentTree[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void printVector(vector<pair<int, int> > v, int n){
    for(int i=0; i<n; i++){
        cout<<"( "<<v[i].first<<" , "<<v[i].second<<" )"<<" ";
    }
    cout<<endl;
}

void createSegmentTree(int treeIndex, int l, int r,  vector<pair<int, int> > &a, vector<int> segmentTree[]){
    if(l == r){
        segmentTree[treeIndex].push_back(a[l].second);
        return;
    }

    int mid = (l+r)/2;
    createSegmentTree(2*treeIndex + 1, l, mid, a, segmentTree);
    createSegmentTree(2*treeIndex + 2, mid + 1, r, a, segmentTree);

    merge(segmentTree[2*treeIndex + 1].begin(),  segmentTree[2*treeIndex + 1].end(), segmentTree[2*treeIndex + 2].begin(),  segmentTree[2*treeIndex + 2].end(), 
        back_inserter(segmentTree[treeIndex])); 
}

int main(){
    int arr[] = {3, 2, 5, 1, 8, 9};

    int n = sizeof(arr)/sizeof(arr[0]);

    vector<pair<int, int> > v;

    for(int i=0; i<n; i++){
        v.push_back(make_pair(arr[i], i));
    }

    sort(v.begin(), v.end());

    printVector(v, n);

    int height = ceil(log2(n));
    int max_size = 2*(pow(2, height)) - 1;
    vector<int> segmentTree[max_size];

    createSegmentTree(0, 0, n - 1, v, segmentTree);

    printSegmentTree(segmentTree, max_size);

    int kSmallestIndex = query(2, 5, 2, n, segmentTree); 
    cout<<"kSmallestIndex: "<<arr[kSmallestIndex]<< endl;

    kSmallestIndex = query(1, 6, 4, n, segmentTree); 
    cout<<"kSmallestIndex: "<<arr[kSmallestIndex]<<endl; 

    return 0;
}