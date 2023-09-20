#include <iostream>
using namespace std;
#include "practice.cpp"

int main()
{
    Fraction f1(10, 2);
    Fraction f2(15, 4);

    Fraction const f3(20, 6); // constant objects can call only constant functions

    cout << f3.getNumerator() << " " << f3.getDenominator() << endl;

    Fraction f4 = f1.add(f2);
    Fraction f5 = f1 + f3;
    f1.print();
    f2.print();
    f4.print();
    Fraction f6 = f1.multiply(f2);
    Fraction f7 = f1 * f2;
    f5.print();
    f6.print();
    f7.print();

    Fraction f8(10, 17);
    Fraction f9(20, 34);
    if (f8 == f9)
    {
        cout << "f8 and f9 are Equal" << endl;
    }
    else
    {
        cout << "f8 and f9 are Unequal" << endl;
    }

    Fraction f10(100, 12);
    Fraction f11 = ++f10;
    f11.print();

    Fraction f12(5, 2);
    Fraction f13 = ++(++f12);
    f13.print();

    Fraction f14(10, 3);
    Fraction f15(5, 2);
    f14.print();
    f15.print();
    f14 += f15;
    f14.print();
    return 0;
}