#include <iostream>
using namespace std;

class ComplexNumbers
{
private:
    int real;
    int imaginary;

public:
    ComplexNumbers(int real, int imaginary) // Parameterized constructor
    {
        this->real = real;
        this->imaginary = imaginary;
    }

    void plus(ComplexNumbers const &c2)
    {
        real = real + c2.real;
        imaginary = imaginary + c2.imaginary;
    }

    void print()
    {
        cout << this->real << " + i" << this->imaginary << endl;
    }

    void multiply(ComplexNumbers const &c2)
    {
        int x = (real * c2.real) - (imaginary * c2.imaginary);
        int y = (real * c2.imaginary) + (c2.real * imaginary);
        this->real = x;
        this->imaginary = y;
    }
};