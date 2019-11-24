#include<iostream>
#include<vector>

using namespace std;

void inorder(int a[], vector<int> &v, int n, int index){
    if(index >= n){
        return;
    }
    inorder(a, v, n, 2*index + 1);
    v.push_back(a[index]);
    inorder(a, v, n, 2*index + 2);
}

void printPairVector(vector<pair<int, int> > v){
    for(int i=0; i<v.size(); i++){
        cout<<v[i].first<<" -- "<<v[i].second<<endl;
    }
    cout<<endl;
}

void printVector(vector<int> v){
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

int minSwaps(vector<int> v){
    int n = v.size();
    vector<pair<int, int> > arrPos(n);

    for(int i=0; i<n; i++){
        (arrPos[i]).first = v[i];
        (arrPos[i]).second = i;
    }

    printPairVector(arrPos);

    sort(arrPos.begin(), arrPos.end());

    printPairVector(arrPos);

    int ans = 0;

    vector<bool> vis(n, false); 

    for(int i=0; i<n; i++){
        if(vis[i] || arrPos[i].second == i){
            continue;
        }

        int cycleCount = 0;

        int j=i;

        while(!vis[j]){
            vis[j] = true;
            j=arrPos[j].second;
            cycleCount++;
        }

        if(cycleCount > 0){
            ans = ans + (cycleCount -1);
        }
    }

    return ans;
}

int main(){

    int a[] = {5, 6, 7, 8, 9, 10, 11};
    int n = sizeof(a)/sizeof(a[0]);

    vector<int> v;

    inorder(a, v, n, 0);

    printVector(v);

    cout<<minSwaps(v)<<endl;

    return 0;
}