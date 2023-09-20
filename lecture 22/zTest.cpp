#include <iostream>
using namespace std;
#include "vehicle.cpp"
#include "car.cpp"

int main()
{
    // vehicle v;
    // v.color = "blue";
    // v.numTyres = 5; // private member cannot be accessed
    // v.maxSpeed = 10; // protected member can only be accessed through the derived classes

    car c;
    c.color = "red";
    c.numGears = 5;

    return 0;
}