class Polynomial
{
public:
    int *degCoeff;
    int capacity;

    Polynomial()
    {
        degCoeff = new int[5 + 1];
        capacity = 5;
        for (int i = 0; i <= capacity; i++)
        {
            degCoeff[i] = 0;
        }
    }

    Polynomial(int capacity)
    {
        this->degCoeff = new int[capacity + 1];
        this->capacity = capacity;
        for (int i = 0; i <= capacity; i++)
        {
            degCoeff[i] = 0;
        }
    }

    Polynomial(Polynomial const &p)
    {
        this->capacity = p.capacity;
        this->degCoeff = new int[capacity + 1];
        for (int i = 0; i <= capacity; i++)
        {
            degCoeff[i] = p.degCoeff[i];
        }
    }

    void setCoefficient(int degree, int coefficient)
    {
        if (degree <= capacity)
        {
            degCoeff[degree] = coefficient;
        }
        else
        {
            int *newDegCoeff = new int[degree + 1];
            for (int i = 0; i <= capacity; i++)
            {
                newDegCoeff[i] = degCoeff[i];
            }
            for (int i = capacity + 1; i <= degree; i++)
            {
                newDegCoeff[i] = 0;
            }
            newDegCoeff[degree] = coefficient;
            delete[] degCoeff;
            degCoeff = newDegCoeff;
            capacity = degree + 1;
        }
    }

    Polynomial operator+(Polynomial const &p)
    {
        int cap = max(capacity, p.capacity);
        // cout << "Cap" << cap << endl;
        Polynomial p1(cap);
        for (int i = 0; i <= cap; i++)
        {
            if (i < capacity && i < p.capacity)
            {
                p1.degCoeff[i] = p.degCoeff[i] + degCoeff[i];
            }
            else if (i <= capacity)
            {
                p1.degCoeff[i] = degCoeff[i];
            }
            else
            {
                p1.degCoeff[i] = p.degCoeff[i];
            }
        }
        return p1;
    }

    Polynomial operator-(Polynomial const &p)
    {
        int cap = max(capacity, p.capacity);
        // cout << "Cap" << cap << endl;
        Polynomial p1(cap);
        for (int i = 0; i <= cap; i++)
        {
            if (i < capacity && i < p.capacity)
            {
                p1.degCoeff[i] = degCoeff[i] - p.degCoeff[i];
            }
            else if (i <= capacity)
            {
                p1.degCoeff[i] = degCoeff[i];
            }
            else
            {
                p1.degCoeff[i] = -p.degCoeff[i];
            }
        }
        return p1;
    }

    Polynomial operator*(Polynomial const &p)
    {
        int cap = p.capacity + capacity;
        Polynomial p1(cap);
        for (int i = 0; i <= capacity; i++)
        {
            for (int j = 0; j <= p.capacity; j++)
            {
                p1.degCoeff[i + j] += p.degCoeff[j] * degCoeff[i];
            }
        }
        return p1;
    }

    void operator=(Polynomial const &p)
    {
        this->capacity = p.capacity;
        this->degCoeff = new int[capacity + 1];
        for (int i = 0; i <= capacity; i++)
        {
            degCoeff[i] = p.degCoeff[i];
        }
    }

    void print() const
    {
        for (int i = 0; i <= capacity; i++)
        {
            if (degCoeff[i] != 0)
            {
                cout << degCoeff[i] << "x" << i << " ";
            }
        }
        cout << endl;
    }
};