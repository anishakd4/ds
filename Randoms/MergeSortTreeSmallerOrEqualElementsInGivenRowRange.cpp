#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int queryUtil(int node, int ss, int se, int qs, int qe, int k, vector<int> a[], vector<int> segmentTree[]){
    if(se < qs || ss > qe){
        return 0;
    }

    if(qs <= qs && qe >= se){
        return upper_bound(segmentTree[node].begin(), segmentTree[node].end(), k) - segmentTree[node].begin();
    }

    int mid = (ss + se)/2;

    return queryUtil(2*node + 1, ss, mid, qs, qe, k, a, segmentTree) + queryUtil(2*node+2, mid+1, se, qs, qe, k, a, segmentTree);
}

int query(int start, int end, int k, vector<int> a[], int n, vector<int> segmentTree[]){
    return queryUtil(0, 0, n-1, start, end, k, a, segmentTree);
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

void createSegmentTree(int si, int ss, int se, vector<int> a[], vector<int> segmentTree[]){
    if(ss == se){
        segmentTree[si] = a[ss];
        return;
    }

    int mid = (ss + se)/2;

    createSegmentTree(2*si + 1, ss, mid, a, segmentTree);
    createSegmentTree(2*si + 2, mid+1, se, a, segmentTree);

    merge(segmentTree[2*si + 1].begin(), segmentTree[2*si + 1].end(), segmentTree[2*si + 2].begin(), segmentTree[2*si + 2].end(), back_inserter(segmentTree[si]));
}

int main(){
    int n = 3;

    int arr[][3] = {{2, 4, 5}, {3, 4, 9}, {6, 8, 10}};

    vector<int> a[n];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            a[i].push_back(arr[i][j]);
        }
    }

    int height = ceil(log2(n));

    cout<<"height="<<height<<endl;
    int max_size = 2*(pow(2, height)) - 1;
    cout<<"max_size="<<max_size<<endl;

    vector<int> segmentTree[max_size];
    createSegmentTree(0, 0, n-1, a, segmentTree);

    printSegmentTree(segmentTree, max_size);


    cout << query(0, 1, 5, a, n, segmentTree) << endl; 
    cout << query(1, 2, 1, a, n, segmentTree) << endl; 
    cout << query(0, 2, 6, a, n, segmentTree) << endl;

    return 0;
}