#include<iostream>
#include<unordered_map>

using namespace std;

struct item{
    string name;
    int price;
};

int countItems(item list1[], item list2[], int m, int n){
    unordered_map<string, int> myMap;
    int count = 0;
    for(int i=0; i<m; i++){
        myMap[list1[i].name] = list1[i].price;
    }

    for(int i=0; i<n; i++){
        if(myMap.find(list2[i].name) != myMap.end() && myMap[list2[i].name] != list2[i].price){
            count++;
        }
    }

    return count;
}

int main(){

    item list1[] = {{"apple", 60}, {"bread", 20},  
                    {"wheat", 50}, {"oil", 30}}; 
    item list2[] = {{"milk", 20}, {"bread", 15},  
                    {"wheat", 40}, {"apple", 60}}; 
      
    int m = sizeof(list1) / sizeof(list1[0]); 
    int n = sizeof(list2) / sizeof(list2[0]);

    cout << "Count = " << countItems(list1, list2, m, n) <<endl; 

    return 0;
}