#include<iostream>
#include<string>

using namespace std;

int sumAtKthLevel(string tree, int k){
    int level = -1;
    int sum=0;
    for(int i=0; i<tree.size(); i++){
        if(tree[i] == ')'){
            level--;
        }else if(tree[i] == '('){
            level++;
        }else{
            if(level == k){
                sum = sum + (tree[i] - '0');
            }
        }
    }
    return sum;
}

int main(){
    string tree = "(0(5(6()())(4()(9()())))(7(1()())(3()())))";
    int k=2;
    cout<<sumAtKthLevel(tree, k)<<endl;

    return 0;
}
