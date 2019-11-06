#include<iostream>
#include<vector>

using namespace std;

class Stack{
    int minn;
    int size;
    vector<pair<int, int> > arr;
    const int MAXX = 1000;

    public:
        Stack(){
            minn = INT_MAX;
            size = -1;
        }

        int AddElement(int element){
            if(size > MAXX){
                cout<<"Stack overflow"<<endl;
                return 0;
            }

            if(element < minn){
                minn = element;
            }

            arr.push_back(make_pair(element, minn));
            size++;
            return 1;
        }

        int RemoveLastElement(){
            if(size == -1){
                cout<<"stack empty"<<endl;
                return 0;
            }

            size--;
            arr.pop_back();

            minn = arr[size].second;

            return 1;
        }

        int GetLastElement(){
            if(size == -1){
                cout<<"No elements"<<endl;
                return -1;
            }
            return arr[size].first;
        }
 
        int GetMin(){
            if(size == -1){
                cout<<"empty stack"<<endl;
                return -1;
            }

            return arr[size].second;
        }   
};

int main(){

    Stack s;
    int success = s.AddElement(5); 
    if (success == 1) 
        cout << "5 inserted successfully\n"; 
  
    success = s.AddElement(7); 
    if (success == 1) 
        cout << "7 inserted successfully\n"; 
  
    success = s.AddElement(3); 
    if (success == 1) 
        cout << "3 inserted successfully\n"; 
    int min1 = s.GetMin(); 
    cout << "min element  :: " << min1 << endl; 
  
    success = s.RemoveLastElement(); 
    if (success == 1) 
        cout << "removed successfully\n"; 
  
    success = s.AddElement(2); 
    if (success == 1) 
        cout << "2 inserted successfully\n"; 
  
    success = s.AddElement(9); 
    if (success == 1) 
        cout << "9 inserted successfully\n"; 
    int last = s.GetLastElement(); 
    cout << "Last element :: " << last << endl; 
  
    success = s.AddElement(0); 
    if (success == 1) 
        cout << "0 inserted successfully\n"; 
    min1 = s.GetMin(); 
    cout << "min element  :: " << min1 << endl; 
  
    success = s.RemoveLastElement(); 
    if (success == 1) 
        cout << "removed successfully\n"; 
  
    success = s.AddElement(11); 
    if (success == 1) 
        cout << "11 inserted successfully\n"; 
    min1 = s.GetMin(); 
    cout << "min element  :: " << min1 << endl; 

}