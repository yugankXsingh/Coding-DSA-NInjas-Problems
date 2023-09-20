#include <iostream>
using namespace std;
#include <string>
#include "ourmap.h"

int main()
{
    ourmap<int> map;

    for (int i = 0; i < 10; i++)
    {
        char c = '0' + i;
        string key = "abc";
        key = key + c;
        int value = i + 1;

        map.insert(key, value);
        cout << "loadFactor : " << map.getloadFactor() << endl;
    }

    cout << map.size() << endl;

    map.remove("abc2");
    map.remove("abc7");

    cout << map.size() << endl;

    for (int i = 0; i < 10; i++)
    {
        char c = '0' + i;
        string key = "abc";
        key = key + c;

        cout << key << " : " << map.getValue(key) << endl;
    }

    return 0;
}