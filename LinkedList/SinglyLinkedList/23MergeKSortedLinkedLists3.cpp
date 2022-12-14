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

Node *mergeKLists(Node *arr[], int k)
{
    Node *head = NULL;
    while (1)
    {
        int a = 0;
        Node *curr;
        int z;
        int min = INT_MAX;

        for (int i = 0; i < k; i++)
        {
            if (arr[i] != NULL)
            {
                a++;
                if (arr[i]->data < min)
                {
                    min = arr[i]->data;
                    z = i;
                }
            }
        }
        if (a != 0)
        {
            arr[z] = arr[z]->next;
            Node *temp = new Node(min);
            if (head == NULL)
            {
                curr = head = temp;
            }
            else
            {
                curr->next = temp;
                curr = temp;
            }
        }
        else
        {
            return head;
        }
    }
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

    Node *head = mergeKLists(arr, k - 1);

    printList(head);
    return 0;
}