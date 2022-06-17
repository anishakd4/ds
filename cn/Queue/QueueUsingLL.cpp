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
    int data;
    Node<T> *next;

    Node(T data)
    {
        this->data = data;
        next = NULL;
    }
};

template <typename T>
class Queue
{
    Node<T> *head;
    Node<T> *tail;
    int size;

public:
    Queue()
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    int getSize() const
    {
        return size;
    }

    bool isEmpty() const { return size == 0; }

    void enqueue(T element)
    {
        Node<T> *newNode = new Node<T>(element);
        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    T front()
    {
        if (size == 0)
        {
            return 0;
        }
        return head->data;
    }

    T dequeue()
    {
        if (size == 0)
        {
            return 0;
        }
        T ans = head->data;
        Node<T> *next = head->next;
        delete[] head;
        head = next;
        size--;
        return ans;
    }
};

int main()
{
    Queue<int> q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    q.enqueue(70);

    cout << q.front() << endl;
    cout << q.getSize() << endl;
    q.dequeue();
    q.dequeue();
    q.dequeue();
    cout << q.front() << endl;
    cout << q.getSize() << endl;

    return 0;
}