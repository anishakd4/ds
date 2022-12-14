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

Node *mergeKLists(Node *arr[], int count)
{
    if (count == 0)
    {
        Node *x = new Node();
        return x;
    }
    Node *head_main = arr[0];
    for (int i = 1; i <= count; i++)
    {
        Node *head_0 = head_main;
        while (true)
        {
            Node *head_i = arr[i];

            if (head_i == NULL)
            {
                break;
            }

            if (head_0->data >= head_i->data)
            {
                arr[i] = head_i->next;
                head_i->next = head_0;
                arr[0] = head_i;
                head_main = head_i;
                head_0 = head_main;
            }
            else
            {
                while (head_0->next != NULL)
                {
                    if (head_i->data <= head_0->next->data)
                    {
                        arr[i] = head_i->next;
                        head_i->next = head_0->next;
                        head_0->next = head_i;
                        break;
                    }
                    head_0 = head_0->next;

                    if (head_0->next == NULL)
                    {
                        arr[i] = head_i->next;
                        arr[i] = NULL;
                        head_0->next = head_i;
                        break;
                    }
                }
            }
        }
    }
    return head_main;
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