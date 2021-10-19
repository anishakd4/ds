#include <iostream>

using namespace std;
#define MAX 1000

bool has[MAX + 1][2];

bool search(int x)
{
    if (x >= 0)
    {
        return has[x][0];
    }
    else
    {
        return has[abs(x)][1];
    }
}

void insert(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] >= 0)
        {
            has[a[i]][0] = true;
        }
        else
        {
            has[abs(a[i])][1] = true;
        }
    }
}

int main()
{
    int a[] = {-1, 9, -5, -8, -5, -2};

    int n = sizeof(a) / sizeof(a[0]);

    insert(a, n);

    if (search(-5))
    {
        cout << "Present" << endl;
    }
    else
    {
        cout << "Not Present" << endl;
    }

    return 0;
}