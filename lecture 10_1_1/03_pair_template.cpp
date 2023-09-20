#include <iostream>
using namespace std;

template <typename T, typename V>

class Pair
{
    T x;
    V y;

public:
    T getX()
    {
        return x;
    }

    T setX(T x)
    {
        this->x = x;
    }

    V getY()
    {
        return y;
    }

    V setY(V y)
    {
        this->y = y;
    }
};