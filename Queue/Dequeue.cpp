#include<iostream>
#include<iomanip>
#include<algorithm>
#include<string>
#include<cstring>
#include<vector>
#include<cmath>
#include <map>
#include<climits>
//climits for INT_MIN
#include <unordered_map>
using namespace std;
class Dequeue
{
    int *arr;
    int front;
    int rear;
    int size;
public:
    Dequeue(int size){
        this->size = size;
        this->arr = new int[size];
        front = rear = -1;
    }
};

Dequeue::Dequeue(/* args */)
{
}

Dequeue::~Dequeue()
{
}

int main()
{
    return 0;
}