#include<iostream>

using namespace std;

void myCopy(char s1[], char s2[]){
    int i=0;
    for(i=0; s1[i] != '\0'; i++){
        s2[i] = s1[i];
    }
    s2[i] = '\0';
}

int main(){

    char s1[100] = "GEEKSFORGEEKS";
    char s2[100] = "";

    myCopy(s1, s2);

    cout<<s2<<endl;

    return 0;
}