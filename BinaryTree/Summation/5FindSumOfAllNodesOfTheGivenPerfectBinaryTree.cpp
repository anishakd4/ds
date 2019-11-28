#include<iostream>
#include<math.h>

using namespace std;

int sumNodes(int l){
    int leafNodesCount = pow(2, l-1);

    int sum = ((leafNodesCount) * (leafNodesCount + 1) / 2);

    return (sum * l);
}

int main(){
    int l = 3; 
    cout << sumNodes(l)<<endl;

    return 0;
}