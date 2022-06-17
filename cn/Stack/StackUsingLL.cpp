#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <cmath>
#include <map>
#include <climits>
// climits for INT_MIN
#include <unordered_map>
using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node<T> *next;

    Node(T data)
    {
        this->data = data;
        next = NULL;
    }
};

template <typename T> // this line belongs to this class only. We might need to add this to each class
class Stack
{
private:
    int size;
    Node<T> *head;

public:
    Stack()
    {
        head = NULL;
        size = 0;
    }

    int getSize() const
    {
        return size;
    }

    bool isEmpty() const
    {
        return size == 0;
    }

    void push(T element)
    {
        Node<T> *newNode = new Node<T>(element);
        newNode->next = head;
        head = newNode;
        size++;
    }

    T pop()
    {
        if (isEmpty())
        {
            return 0;
        }
        T ans = head->data;
        Node<T> *temp = head;
        head = head->next;
        delete temp;
        size--;
        return ans;
    }

    T top() const
    {
        if (isEmpty())
        {
            return 0;
        }
        return head->data;
    }
};

int main()
{
    Stack<char> s;
    s.push(100);
    s.push(101);
    s.push(102);
    s.push(103);
    s.push(104);

    cout << s.getSize() << endl;
    cout << s.top() << endl;

    cout << s.pop() << endl;

    cout << s.top() << endl;
    cout << s.getSize() << endl;

    cout << s.isEmpty() << endl;
    return 0;
}