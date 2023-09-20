#include <iostream>
using namespace std;
#include <unordered_map>
#include <string>

string uniqueChar(string str)
{
    unordered_map<char, int> map;

    for (int i = 0; i < str.length(); i++)
    {
        if (map.count(str[i]) > 0)
        {
            // map already has a freq corresponding to the key str[i]
            // hence , we update that freq
            map[str[i]]++;
            continue;
        }

        // if map does not have freq corresponding to str[i]
        // set the freq of str[i] to 1
        map[str[i]] = 1;
    }

    // now our string str is mapped

    string output;

    for (int i = 0; i < str.length(); i++)
    {
        if (map[str[i]] == 0)
        {
            continue;
        }

        if (map[str[i]] == 1)
        {
            output.push_back(str[i]);
            continue;
        }

        output.push_back(str[i]);
        map[str[i]] = 0;
    }

    return output;
}

int main()
{
    string str;
    cin>>str;
    cout<<uniqueChar(str);
    return 0;
}