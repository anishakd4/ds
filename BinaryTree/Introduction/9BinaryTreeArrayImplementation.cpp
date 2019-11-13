#include<iostream>

using namespace std;

char tree[10];

void root(char key){
    if(tree[0] != '\0'){
        cout<<"Tree already had root"<<endl;
    }else{
        tree[0] = key;
    }
}

void setLeft(char key, int parent){
    if(tree[parent] == '\0'){
        cout<<"No parent"<<endl;
    }else{
        tree[2*parent + 1] = key;
    }
}

void setRight(char key, int parent){
    if(tree[parent] == '\0'){
        cout<<"No parent"<<endl;
    }else{
        tree[2*parent + 2] = key;
    }
}

void printTree(){
    cout<<"Tree: "<<endl;

    for(int i=0; i<10; i++){
        if(tree[i] != '\0'){
            cout<<tree[i]<<" ";
        }else{
            cout<<"- ";
        }
    }
}

int main(){

    root('A');
    setRight('C', 0); 
    setLeft('D', 1); 
    setRight('E', 1); 
    setRight('F', 2); 

    printTree(); 
    
    return 0;
}