#include <climits> //as we use INT_MIN

class StackUsingArray
{
private:
    int *data;
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
        data = new int[4];
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

    void push(int element)
    {
        if (nextIndex == capacity)
        {
            // cout << "Stack full!" << endl;
            // return;
            int *newData = new int[2 * capacity];
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

    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty!" << endl;
            return INT_MIN;
        }
        nextIndex--;
        return data[nextIndex];
    }

    int top()
    {
        if (isEmpty())
        {
            cout << "Stack empty!" << endl;
            return INT_MIN;
        }
        return data[nextIndex - 1];
    }
};
