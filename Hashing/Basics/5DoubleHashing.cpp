#include <iostream>
#define TABLE_SIZE 12
#define PRIME 7

using namespace std;

class DoubleHash
{

    int *hashTable;
    int curr_size;

public:
    DoubleHash()
    {
        hashTable = new int[TABLE_SIZE];
        curr_size = 0;
        for (int i = 0; i < TABLE_SIZE; i++)
        {
            hashTable[i] = -1;
        }
    }

    bool isFull()
    {
        return (curr_size == TABLE_SIZE);
    }

    int hash1(int key)
    {
        return (key % TABLE_SIZE);
    }

    int hash2(int key)
    {
        return (PRIME - (key % PRIME));
    }

    void displayHash()
    {
        for (int i = 0; i < TABLE_SIZE; i++)
        {
            if (hashTable[i] != -1)
            {
                cout << i << " --> " << hashTable[i] << endl;
            }
            else
            {
                cout << i << endl;
            }
        }
    }

    void search(int key)
    {
        int index1 = hash1(key);
        int index2 = hash2(key);
        int i = 0;
        while (hashTable[index1 + i * index2] != key)
        {
            if (hashTable[index1 + i * index2] == -1)
            {
                cout << key << " does not exist" << endl;
                return;
            }
            i++;
        }
        cout << key << " found" << endl;
    }

    void insert(int key)
    {
        if (isFull())
        {
            return;
        }

        int index1 = hash1(key);
        if (hashTable[index1] != -1)
        {
            int index2 = hash2(key);
            int i = 1;
            while (1)
            {
                int nextIndex = (index1 + i * index2) % TABLE_SIZE;
                if (hashTable[nextIndex] != -1)
                {
                    hashTable[nextIndex] = key;
                    break;
                }
                i++;
            }
        }
        else
        {
            hashTable[index1] = key;
        }
        curr_size++;
    }
};

int main()
{

    int a[] = {19, 27, 36, 10, 64};
    int n = sizeof(a) / sizeof(a[0]);
    DoubleHash hash;
    for (int i = 0; i < n; i++)
    {
        hash.insert(a[i]);
    }

    hash.search(36);
    hash.search(100);
    hash.displayHash();

    return 0;
}