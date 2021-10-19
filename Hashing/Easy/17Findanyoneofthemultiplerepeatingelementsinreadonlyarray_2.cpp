#include<iostream>
#include<unordered_map>

using namespace std;

int findRepeatingNumber(int arr[], int n, int arr_size){
    int sq = sqrt(n);

    int range = (n/sq) + 1;

    int count[range] = {0};

    for(int i=0; i<n; i++){
        count[(arr[i])/sq]++;
    }

    int selected_block = range - 1; 
    for (int i = 0; i < range - 1; i++) 
    { 
        if (count[i] > sq) 
        { 
            selected_block = i; 
            break; 
        } 
    } 

    unordered_map<int, int> m; 
    for (int i = 0; i <= n; i++) 
    { 
        // checks if the element belongs to the 
        // selected_block 
        if ( ((selected_block * sq) < arr[i]) && 
                (arr[i] <= ((selected_block + 1) * sq))) 
        { 
            m[arr[i]]++; 
  
            // repeating element found 
            if (m[arr[i]] > 1) 
                return arr[i]; 
        } 
    }

    return sq;
}

int main(){
    int arr[] = {1, 1, 2, 3, 5, 4};

    int arr_size = sizeof(arr)/sizeof(arr[0]);

    int n = 5;

    cout<<findRepeatingNumber(arr, n, arr_size)<<endl;

    return 0;
}