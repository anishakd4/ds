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
#include "Node.cpp"

/*
Time complexity: O(n^2)

n   ->  Time complexity
1 -> k
2 ->1
3 ->2
4 ->3
5 ->4
......
n ->n-1

Time complexity: O(n^2)
*/

// Node *takeInput()
// {
//     int data;
//     cin >> data;
//     Node *head = NULL;
//     while (data != -1)
//     {
//         Node *newNode = new Node(data);
//         if (head == NULL)
//         {
//             head = newNode;
//         }
//         else
//         {
//             Node *temp = head;
//             while (temp->next != NULL)
//             {
//                 temp = temp->next;
//             }
//             temp->next = newNode;
//         }
//         cin >> data;
//     }
//     return head;
// }

// Better time complexity as for each new node we are doing constant operations
Node *takeInput()
{
    int data;
    cin >> data;
    Node *head = NULL;
    Node *tail = NULL;
    while (data != -1)
    {
        // Node newNode(data); this will create issue as static memory allocation is scope specific
        // The memory will be deallocated after each iteration
        Node *newNode = new Node(data); // while dynamic memory allocation's deallocation is done manually.
        // These are not deallocated until we deallocate them explicitly
        if (head == NULL)
        {
            // head = &newNode;
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = tail->next;
            // OR tail=newNode;
        }
        cin >> data;
    }
    return head;
}
/*

    newNode
    _________________           _____________________
    |       100     |           |     10   |  NULL  | address=100   These are not deallocated after iteration
    |_______________|           |__________|________|               as these are dynamic memory allocation
    deallocated after
    iteration as static
    memory

    newNode
    _________________           _____________________
    |       100     |           |     10   |  NULL  | address=100
    |_______________|           |__________|________|
    deallocated after
    iteration as static
    memory

    newNode
    _________________           _____________________
    |       100     |           |     10   |  NULL  | address=100
    |_______________|           |__________|________|
    deallocated after
    iteration as static
    memory

*/

/*
T(n) =T(n-1) + (n-1)
T(n-1) =T(n-2) + (n-1)
T(n-2) =T(n-3) + (n-2)
T(n-3) =T(n-4) + (n-3)
................................
=
T(n) = (n-1) + (n-2) + (n-3)+....1
O(n^2) time complexity
*/
Node *reverseLL(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *smallAns = reverseLL(head->next);

    Node *temp = smallAns;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = head;
    head->next = NULL;
    return smallAns;
}

class Pair
{
public:
    Node *head;
    Node *tail;
};

// Double node approach to reverse Linked list
/*
T(n) = T(n-1) + k;
T(n-1) = T(n-2) + k;
T(n-2) = T(n-3) + k;
..............
=
T(n) = nk
O(n)
*/
Pair reverseLL_2(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        Pair ans;
        ans.head = head;
        ans.tail = head;
        return ans;
    }

    Pair smallAns = reverseLL_2(head->next);
    smallAns.tail->next = head;
    head->next = NULL;
    Pair ans;
    ans.head = smallAns.head;
    ans.tail = head;
    return ans;
}

Node *reverseLL_better(Node *head)
{
    return reverseLL_2(head).head;
}

Node *insertNode(Node *head, int i, int data)
{
    Node *newNode = new Node(data);
    int count = 0;
    Node *temp = head;
    if (i == 0)
    {
        newNode->next = head;
        head = newNode;
        return head;
    }
    // temp != NULL for condition when i > size of the linked list and thus to avoid segmentation fault
    while (temp != NULL && count < i - 1)
    {
        count++;
        temp = temp->next;
    }
    if (temp != NULL)
    {
        newNode->next = temp->next;
        temp->next = newNode;
    }
    return head;
}

void printMiddle(Node *head)
{
    Node *slow_ptr = head;
    Node *fast_ptr = head;

    if (head != NULL)
    {
        while (fast_ptr != NULL && fast_ptr->next != NULL)
        {
            fast_ptr = fast_ptr->next->next;
            slow_ptr = slow_ptr->next;
        }
        cout << "The middle element is [" << slow_ptr->data << "]" << endl;
    }
}

void print(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    // statically initialize
    Node n1(1);
    Node *head = &n1;
    Node n2(2);
    n1.next = &n2;
    cout << n1.data << " " << n2.data << endl;

    // Dynamically initialize
    Node *n3 = new Node(10);
    Node *head2 = n3;
    Node *n4 = new Node(20);
    n3->next = n4;

    // create linked list of 5 elements
    Node a(1);
    Node *head3 = &a;
    Node b(2);
    Node c(3);
    Node d(4);
    Node e(5);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    print(head3);

    // take input
    Node *head4 = takeInput();
    print(head4);

    head4 = insertNode(head4, 0, 99);
    print(head4);

    printMiddle(head4);
    print(head4);

    cout << "reverse linked list" << endl;
    Node *rev1 = reverseLL(head4);
    print(head4);
    print(rev1);

    rev1 = reverseLL_better(rev1);
    print(rev1);

    return 0;
}

// First node of linked list is called Head node and last node is called Tail node.
// We save the address of Head node, if we loose it we will loose the whole linked list