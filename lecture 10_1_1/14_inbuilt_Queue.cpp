#include <iostream>
using namespace std;
#include <queue>

int main()
{
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);

    cout << q.front() << endl;
    q.pop();
    q.pop();
    cout << q.size() << endl;
    cout << q.front() << endl;
    cout << q.empty() << endl;

    while (!q.empty())
    {
        cout << q.front() << endl;
        q.pop();
    }
    return 0;
}