#include <iostream>
using namespace std;

class Fraction
{
private:
    int numerator;
    int denominator;

public:
    Fraction(int numerator, int denominator)
    {
        this->numerator = numerator;
        this->denominator = denominator;
    }

    void print() const
    {
        cout << numerator << " / " << denominator << endl;
    }

    int getNumerator() const
    {
        return numerator;
    }
    int getDenominator() const
    {
        return denominator;
    }

    void simplify()
    {
        int gcd = 1;
        int j = min(numerator, denominator);
        int i;
        for (i = 1; i <= j; i++)
        {
            if (numerator % i == 0 && denominator % i == 0)
            {
                gcd = i;
            }
        }

        numerator = numerator / gcd;
        denominator = denominator / gcd;
    }

    Fraction add(const Fraction &f2) const
    {
        int LCM = denominator * f2.denominator;
        int x = LCM / denominator;
        int y = LCM / f2.denominator;

        int num = x * numerator + y * f2.numerator;
        Fraction fNew(num, LCM);
        fNew.simplify();
        return fNew;
    }

    Fraction multiply(Fraction const &f2) const
    {
        int x = numerator * f2.numerator;
        int y = denominator * f2.denominator;
        Fraction fNew(x, y);
        fNew.simplify();
        return fNew;
    }
    // operator overloading

    Fraction operator+(Fraction const &f2) const
    {
        int LCM = denominator * f2.denominator;
        int x = LCM / denominator;
        int y = LCM / f2.denominator;

        int num = (x * numerator) + (y * f2.numerator);
        Fraction fNew(num, LCM);
        fNew.simplify();
        return fNew;
    }

    Fraction operator*(Fraction const &f2) const
    {
        int x = numerator * f2.numerator;
        int y = denominator * f2.denominator;
        Fraction fNew(x, y);
        fNew.simplify();
        return fNew;
    }

    bool operator==(Fraction const &f2)
    {
        simplify();
        // f2.simplify(); // will not work as f2 has a constant reference

        Fraction f3(f2.numerator, f2.denominator);
        f3.simplify();

        if (numerator == f3.numerator && denominator == f3.denominator)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    Fraction &operator++() // pre-increment
    {
        numerator = numerator + denominator;
        simplify();
        return *this;
    }

    Fraction operator++(int) // post increment
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

        int num = x * numerator + y * f2.numerator;

        numerator = num;
        denominator = LCM;
        simplify();

        return *this;
    }
};