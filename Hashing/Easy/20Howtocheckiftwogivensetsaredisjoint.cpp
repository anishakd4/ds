#include<iostream>
#include<unordered_map>

using namespace std;

bool areDisjoint(int set1[], int set2[], int n1, int n2){
    unordered_map<int, int> myhash;

    for(int i=0; i<n1; i++){
        myhash[set1[i]]++;
    }

    for(int i=0; i<n2; i++){
        if(myhash.find(set2[i]) != myhash.end()){
            return false;
        }
    }
    return true;
}

int main(){

    int set1[] = {10, 5, 3, 4, 6}; 
    int set2[] = {8, 7, 9, 3};

    int n1 = sizeof(set1)/sizeof(set1[0]);
    int n2 = sizeof(set2)/sizeof(set2[0]);
    if (areDisjoint(set1, set2, n1, n2)) {
        cout << "Yes" <<endl; 
    }
    else{
        cout << "No" <<endl;
    }

    return 0;
}