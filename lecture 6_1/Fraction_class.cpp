#include <iostream>
using namespace std;
class Fraction
{
private:
    int numerator;
    int denominator;

public:
    Fraction(int numerator, int denominator) // parameterized constructor
    {
        this->numerator = numerator;
        this->denominator = denominator;
    }

    void print() const
    {
        cout << this->numerator << "/" << this->denominator << endl;
    }

    int getNumerator() const // constant functions
    {
        return numerator;
    }
    int getDenominator() const
    {
        return denominator;
    }

    void simplify()
    {
        int gcd = 1;                                     // HCF
        int j = min(this->numerator, this->denominator); // HCF cannot exceed the minimum among both.

        for (int i = 1; i <= j; i++)
        {
            if (this->numerator % i == 0 && this->denominator % i == 0)
            {
                gcd = i;
            }
        }

        this->numerator = this->numerator / gcd;
        this->denominator = this->denominator / gcd;
    }

    Fraction add(Fraction const &f2)
    {
        int LCM = denominator * f2.denominator;
        int x = LCM / denominator;
        int y = LCM / f2.denominator;
        int num = (x * numerator) + (y * f2.numerator);
        // numerator = num;
        // denominator = LCM;

        Fraction fNew(num, LCM);

        fNew.simplify();
        return fNew;
    }

    // Operator overloading
    Fraction operator+(Fraction const &f2) const // can be marked as constant function
    {
        int LCM = denominator * f2.denominator;
        int x = LCM / denominator;
        int y = LCM / f2.denominator;
        int num = (x * numerator) + (y * f2.numerator);

        Fraction fNew(num, LCM);
        fNew.simplify();
        return fNew;
    }

    Fraction multiply(Fraction const &f2)
    {
        int n = numerator * f2.numerator;
        int d = denominator * f2.denominator;

        Fraction fNew(n, d);

        fNew.simplify();
        return fNew;
    }

    // operator overloading
    Fraction operator*(Fraction const &f2) const // can be marked as constant function
    {
        int n = numerator * f2.numerator;
        int d = denominator * f2.denominator;

        Fraction fNew(n, d);

        fNew.simplify();
        return fNew;
    }

    bool operator==(Fraction const &f2) const // can be marked as constant function
    {
        if (numerator == f2.numerator && denominator == f2.denominator)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    // Pre-increment
    Fraction &operator++()
    {
        numerator = numerator + denominator;
        simplify();
        return *this;
    }
    // Post-increment
    Fraction operator++(int)
    {
        Fraction fNew(numerator, denominator);
        numerator = numerator + denominator;
        simplify();
        fNew.simplify();
        return fNew;
    }

    Fraction &operator+=(Fraction const &f2)
    {
        int LCM = denominator * f2.denominator;
        int x = LCM / denominator;
        int y = LCM / f2.denominator;
        int num = (x * numerator) + (y * f2.numerator);
        numerator = num;
        denominator = LCM;
        simplify();
        return *this;
    }
};