#include <iostream>
using namespace std;
#include <string>
#include <unordered_map>

int main()
{
    unordered_map<string, int> ourmap;
    pair<string, int> p("abc", 1);
    ourmap.insert(p);
    // other way of inserting
    ourmap["def"] = 2;

    // find or access elements
    cout << ourmap["abc"] << endl;
    cout << ourmap.at("def") << endl;
    cout << "size : " << ourmap.size() << endl;

    cout << ourmap["ghi"] << endl; // even if key is not present it gives 0 in output
    cout << "size : " << ourmap.size() << endl;

    // check presence
    if (ourmap.count("ghi") > 0)
    {
        cout << "ghi is present" << endl;
    }
    else
    {
        cout << "ghi is absent" << endl;
    }

    // erase
    ourmap.erase("ghi");
    if (ourmap.count("ghi") > 0)
    {
        cout << "ghi is present" << endl;
    }
    else
    {
        cout << "ghi is absent" << endl;
    }
    cout << "size : " << ourmap.size() << endl;

    return 0;
}