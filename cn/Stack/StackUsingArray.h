// #include <climits> //as we use INT_MIN

// class StackUsingArray
// {
// private:
//     int *data;
//     int nextIndex;
//     int capacity;

// public:
//     // StackUsingArray(int totalSize)
//     // {
//     //     data = new int[totalSize];
//     //     nextIndex = 0;
//     //     capacity = totalSize;
//     // }

//     StackUsingArray()
//     {
//         data = new int[4];
//         nextIndex = 0;
//         capacity = 4;
//     }

//     int size()
//     {
//         return nextIndex;
//     }

//     bool isEmpty()
//     {
//         return (nextIndex == 0);
//     }

//     void push(int element)
//     {
//         if (nextIndex == capacity)
//         {
//             // cout << "Stack full!" << endl;
//             // return;
//             int *newData = new int[2 * capacity];
//             for (int i = 0; i < capacity; i++)
//             {
//                 newData[i] = data[i];
//             }
//             capacity = 2 * capacity;
//             delete[] data;
//             data = newData;
//         }
//         data[nextIndex] = element;
//         nextIndex++;
//     }

//     int pop()
//     {
//         if (isEmpty())
//         {
//             cout << "Stack is empty!" << endl;
//             return INT_MIN;
//         }
//         nextIndex--;
//         return data[nextIndex];
//     }

//     int top()
//     {
//         if (isEmpty())
//         {
//             cout << "Stack empty!" << endl;
//             return INT_MIN;
//         }
//         return data[nextIndex - 1];
//     }
// };

#include <climits> //as we use INT_MIN
template <typename T>

class StackUsingArray
{
private:
    T *data;
    int nextIndex;
    int capacity;

public:
    // StackUsingArray(int totalSize)
    // {
    //     data = new int[totalSize];
    //     nextIndex = 0;
    //     capacity = totalSize;
    // }

    StackUsingArray()
    {
        data = new T[4];
        nextIndex = 0;
        capacity = 4;
    }

    int size()
    {
        return nextIndex;
    }

    bool isEmpty()
    {
        return (nextIndex == 0);
    }

    void push(T element)
    {
        if (nextIndex == capacity)
        {
            // cout << "Stack full!" << endl;
            // return;
            T *newData = new T[2 * capacity];
            for (int i = 0; i < capacity; i++)
            {
                newData[i] = data[i];
            }
            capacity = 2 * capacity;
            delete[] data;
            data = newData;
        }
        data[nextIndex] = element;
        nextIndex++;
    }

    T pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty!" << endl;
            // return INT_MIN;
            return 0; // why 0 because 0 is a standard value which can be used for any data type
            // for int and double it will work for bool it will be false for char it will for 0 ASCII value which is null
            // for pointers it will be treated as null pointer
        }
        nextIndex--;
        return data[nextIndex];
    }

    T top()
    {
        if (isEmpty())
        {
            cout << "Stack empty!" << endl;
            // return INT_MIN;
            return 0;
        }
        return data[nextIndex - 1];
    }
};

// these .h files are header files. These are like normal files. They are library files which we can include
// anywhere and use it.
// we can't have main in .h file. .cpp files can have main

//#include "StackUsingArray.h" this line means all the code from the mentioned file will copied here in the place
// of the include line