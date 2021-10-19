#include<iostream>
#include<unordered_map>

using namespace std;

void printItinerary(unordered_map<string, string> dataSet){
    unordered_map<string, string> reverseMap;

    unordered_map<string, string> :: iterator it;
    for(it=dataSet.begin(); it!=dataSet.end(); it++){
        reverseMap[it->second] = it->first;
    } 

    string start;

    for(it=dataSet.begin(); it!=dataSet.end(); it++){
        if(reverseMap.find(it->first) == reverseMap.end()){
            start = it->first;
            break;
        }
    }  

    it=dataSet.find(start);
    while(it != dataSet.end()){
        cout<<it->first<<" : "<<it->second<<endl;
        it=dataSet.find(it->second);
    }
}

int main(){

    unordered_map<string, string> dataSet; 
    dataSet["Chennai"] = "Banglore"; 
    dataSet["Bombay"] = "Delhi"; 
    dataSet["Goa"] = "Chennai"; 
    dataSet["Delhi"] = "Goa";

    printItinerary(dataSet); 

    return 0;
}