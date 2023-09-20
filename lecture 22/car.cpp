#include <iostream>
using namespace std;
#include "vehicle.cpp"

class car : public vehicle
{
public:
    int numGears;

    car()
    {
        cout << "car class contructor called." << endl;
    }
};