#include<iostream>

using namespace std;

class TwoStacks{
    int* arr;
    int size;
    int top1;
    int top2;

    public:
        TwoStacks(int n){
            size = n;
            arr = new int[size];
            top1 = -1;
            top2 = size ;
        }

        void push1(int x){
            if(top1<top2 - 1){
                top1++;
                arr[top1] = x;
            }else{
                cout<<"Stack overflow"<<endl;
                return;
            }
        }

        void push2(int x){
            if(top1<top2 - 1){
                top2--;
                arr[top2] = x;
            }else{
                cout<<"Stack overflow"<<endl;
                return;
            }
        }

        int pop1(){
            if(top1 >= 0){
                int x = arr[top1];
                top1--;
                return x;
            }else{
                cout<<"Stack underflow"<<endl;
                exit(1);
            }
        }

        int pop2(){
            if(top2 < size){
                int x = arr[top2];
                top2++;
                return x;
            }else{
                cout<<"Stack underflow"<<endl;
                exit(1);
            }
        }
};

int main(){

    TwoStacks ts(5);

    ts.push1(5); 
    ts.push2(10); 
    ts.push2(15); 
    ts.push1(11); 
    ts.push2(7);

    cout << "Popped element from stack1 is " << ts.pop1()<<endl; 
    ts.push2(40); 
    cout << "Popped element from stack2 is " << ts.pop2()<<endl;

    return 0;
}