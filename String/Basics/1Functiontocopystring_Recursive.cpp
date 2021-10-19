#include<iostream>

using namespace std;

void myCopy(char s1[], char s2[], int i){

    s2[i] = s1[i];

    if(s1[i] == '\0'){
        return;
    }

    myCopy(s1, s2, i + 1);
}

int main(){

    char s1[100] = "GEEKSFORGEEKS";
    char s2[100] = "";

    myCopy(s1, s2, 0);

    cout<<s2<<endl;

    return 0;
}