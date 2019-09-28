#include<iostream>

using namespace std;

int max(int a, int b){
    return (a>b)? a : b;
}

int lps(char seq[], int x, int y){
    if(x == y){
        return 1;
    }

    if(x+1 == y && seq[x] == seq[y]){
        return 2;
    }

    if(seq[x] == seq[y]){
        return lps(seq, x+1, y-1) + 2;
    }

    return max(lps(seq, x, y-1), lps(seq, x+1, y));

}

int main(){
    char seq[] = "GEEKSFORGEEKS";

    int n = strlen(seq);

    int result = lps(seq, 0, n-1);

    cout<<result<<endl;

    return 0;
}