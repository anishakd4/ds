#include<iostream>
#include<algorithm>

using namespace std;

// bool isPresent(int B[], int m, int x) { 
//     for (int i = 0; i < m; i++) {
//         if (B[i] == x) {
//             return true; 
//         }
//     }
//     return false; 
// } 

int maxSubarraySum(int a[], int b[], int n, int m){

    sort(b, b + m);

    int max_so_far = INT_MIN  ,curr_max = 0;

    for(int i=0; i<n; i++){
        if(binary_search(b, b+m, a[i])){
            curr_max = 0;
            continue;
        }

        curr_max = max(curr_max + a[i], a[i]);

        max_so_far = max(max_so_far, curr_max);
    }

    return max_so_far;
}

int main(){

    int a[] = {3, 4, 5, -4, 6 };
    int b[] = {1, 8, 5};

    int n = sizeof(a)/sizeof(a[0]);
    int m = sizeof(b)/sizeof(b[0]);

    int answer = maxSubarraySum(a, b, n, m);

    cout<<answer<<endl;

    return 0;
}