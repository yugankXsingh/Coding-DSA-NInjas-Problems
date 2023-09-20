#include <iostream>
using namespace std;

class Polynomial
{
public:
    int *degCoeff;
    int capacity;

    Polynomial()
    {
        degCoeff = new int[5];
        capacity = 5;
        for (int i = 0; i < capacity; i++)
        {
            degCoeff[i] = 0; // initialize each coefficient with 0
        }
    }

    void setCoefficient(int degree, int coeff)
    {
        while (degree >= capacity)
        {
            int *new_degCoeff = new int[2 * capacity];
            for (int i = 0; i < capacity; i++)
            {
                new_degCoeff[i] = degCoeff[i];
            }

            for (int i = capacity; i < 2 * capacity; i++)
            {
                new_degCoeff[i] = 0; // remaining coefficients are now initilaized to 0
            }

            delete[] degCoeff;
            degCoeff = new_degCoeff;
            capacity *= 2;
        }
        degCoeff[degree] = coeff;
    }

    // void print() const
    // {
    //     for (int i = 0; i < capacity; i++)
    //     {
    //         if (degCoeff[i] == 0)
    //             continue;
    //         else
    //         {
    //             cout << degCoeff[i] << "x" << i << " ";
    //         }
    //     }
    //     cout << endl;
    // }

    void print()
    {
        for (int i = 0; i < capacity; i++)
        {

            if (degCoeff[i] != 0)
            {
                cout << degCoeff[i] << "x" << i << " ";
            }
            else
            {
                continue;
            }
        }
        cout << endl;
    }

    // ADD
    Polynomial operator+(Polynomial const &p2)
    {
        int MAX = max(capacity, p2.capacity);

        if (MAX == capacity)
        {
            for (int i = p2.capacity; i < capacity; i++)
            {
                setCoefficient(i, 0);
            }
        }

        if (MAX == p2.capacity)
        {
            for (int i = capacity; i < MAX; i++)
            {
                setCoefficient(i, 0);
            }
        }

        Polynomial p3;
        for (int i = 0; i < MAX; i++)
        {
            p3.setCoefficient(i, degCoeff[i] + p2.degCoeff[i]);
        }

        return p3;
    }

    // SUBSTRACT
    Polynomial operator-(Polynomial const &p2)
    {
        int MAX = max(capacity, p2.capacity);

        if (MAX == capacity)
        {
            for (int i = p2.capacity; i < capacity; i++)
            {
                setCoefficient(i, 0);
            }
        }

        if (MAX == p2.capacity)
        {
            for (int i = capacity; i < MAX; i++)
            {
                setCoefficient(i, 0);
            }
        }

        Polynomial p3;
        for (int i = 0; i < MAX; i++)
        {
            p3.setCoefficient(i, degCoeff[i] - p2.degCoeff[i]);
        }

        return p3;
    }

    // Copy Constructor
    Polynomial(Polynomial const &p2)
    {
        // this->degCoeff = p2.degCoeff; // sahallow copy

        // DEEP COPY
        this->degCoeff = new int[p2.capacity];
        for (int i = 0; i < p2.capacity; i++)
        {
            this->degCoeff[i] = p2.degCoeff[i]; //     copying elements
        }

        capacity = p2.capacity;
    }

    // operator= overloading (copy assingment)
    void operator=(Polynomial const &p2)
    {
        int *newDegCoeff = new int[p2.capacity];
        for (int i = 0; i < p2.capacity; i++)
        {
            newDegCoeff[i] = p2.degCoeff[i];
        }
        delete[] degCoeff;
        degCoeff = newDegCoeff;

        this->capacity = p2.capacity;
    }

    // MULTIPLICATION
    Polynomial operator*(Polynomial const &p2)
    {
        Polynomial p3;

        for (int i = 0; i < capacity; i++)
        {
            Polynomial p;
            for (int j = 0; j < p2.capacity; j++)
            {
                p.setCoefficient(i + j, degCoeff[i] * p2.degCoeff[j]);
            }
            p3 = p3 + p;
        }
        return p3;
    }
};