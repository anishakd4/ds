#include<iostream>

using namespace std;

int main(){
    int arr[] = {10, 324, 45, 90, 9808};

    int n = sizeof(arr)/sizeof(arr[0]);

    int *answer = max_element(arr, arr + n);

    cout<<(*answer)<<endl;

    return 0;
}