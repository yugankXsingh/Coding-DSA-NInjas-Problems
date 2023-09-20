#include <iostream>
using namespace std;
#include "03_pair_template.cpp"

int main()
{
    Pair<Pair<int, double>, char> p1;
    Pair<int, double> p2;
    p2.setX(100);
    p2.setY(100.55);

    p1.setX(p2);
    p1.setY('a');

    cout << p1.getX().getX() << " " << p1.getX().getY() << " " << p1.getY() << endl;

    return 0;
}