class DynamicArray
{

public:
    int *data;
    int nextIndex;
    int capacity;

    DynamicArray()
    {
        data = new int[5];
        nextIndex = 0;
        capacity = 5;
    }

    // custom copy constructor
    DynamicArray(DynamicArray const &d)
    {
        // this->data = d.data; // shallow copy

        // deep copy
        this->data = new int[d.capacity];
        for (int i = 0; i < d.nextIndex; i++)
        {
            this->data[i] = d.data[i];
        }

        this->nextIndex = d.nextIndex;
        this->capacity = d.capacity;
    }

    void operator=(DynamicArray const &d)
    {
        this->data = new int[d.capacity];
        for (int i = 0; i < d.nextIndex; i++)
        {
            this->data[i] = d.data[i];
        }

        this->nextIndex = d.nextIndex;
        this->capacity = d.capacity;
    }

    void add(int element)
    {
        if (nextIndex == capacity)
        {
            cout << "nextIndex == capacity" << endl;
            int *newData = new int[2 * capacity];
            for (int i = 0; i < capacity; i++)
            {
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;
            capacity *= 2;
        }
        data[nextIndex] = element;
        nextIndex++;
    }

    int get(int i)
    {
        if (i < nextIndex)
        {
            return data[i];
        }
        else
        {
            return -1;
        }
    }

    void add(int element, int index)
    {
        if (index < nextIndex)
        {
            data[index] = element;
        }
        else if (index == nextIndex)
        {
            add(element);
        }
        else
        {
            return;
        }
    }

    void print()
    {
        for (int i = 0; i < nextIndex; i++)
        {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};