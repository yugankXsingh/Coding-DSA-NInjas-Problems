#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <unordered_map>

int main()
{
    unordered_map<string, int> ourmap;
    ourmap["abc"] = 1;
    ourmap["abc1"] = 2;
    ourmap["abc2"] = 3;
    ourmap["abc3"] = 4;
    ourmap["abc4"] = 5;
    ourmap["abc5"] = 6;

    // iterator
    unordered_map<string, int>::iterator it = ourmap.begin(); // iterator 'it' now points to the first element of ourmap

    // printing all elements using iterators
    while (it != ourmap.end())
    {
        cout << "key : " << it->first << " Value : " << it->second << endl;
        it++;
    }

    // Iterators for vector
    vector<int> pq;
    pq.push_back(1);
    pq.push_back(2);
    pq.push_back(3);
    pq.push_back(4);
    pq.push_back(5);
    pq.push_back(6);

    vector<int>::iterator it1 = pq.begin();

    while (it1 != pq.end())
    {
        cout << *it1 << endl;
        it1++;
    }

    return 0;
}