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

class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        this->data = 0;
        this->next = NULL;
    }

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << endl;
        node = node->next;
    }
}

Node *SortedMerge(Node *a, Node *b)
{
    Node *result = NULL;
    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);

    if (a->data <= b->data)
    {
        result = a;
        result->next = SortedMerge(a->next, b);
    }
    else
    {
        result = b;
        result->next = SortedMerge(a, b->next);
    }

    return result;
}

Node *mergeKLists(Node *arr[], int last)
{
    while (last != 0)
    {
        int i = 0, j = last;
        while (i < j)
        {
            arr[i] = SortedMerge(arr[i], arr[j]);
            i++, j--;
            if (i >= j)
            {
                last = j;
            }
        }
    }

    return arr[0];
}
int main()
{
    int k = 3;
    int n = 4;
    Node *arr[k];

    arr[0] = new Node(1);
    arr[0]->next = new Node(3);
    arr[0]->next->next = new Node(5);
    arr[0]->next->next->next = new Node(7);

    arr[1] = new Node(-1);
    arr[1]->next = new Node(4);
    arr[1]->next->next = new Node(6);
    arr[1]->next->next->next = new Node(8);

    arr[2] = new Node(0);
    arr[2]->next = new Node(9);
    arr[2]->next->next = new Node(10);
    arr[2]->next->next->next = new Node(11);

    // Merge all lists
    Node *head = mergeKLists(arr, k - 1);

    printList(head);
    return 0;
}