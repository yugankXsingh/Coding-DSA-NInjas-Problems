#include <iostream>
using namespace std;
#include "07_stackUsingLL.h" // files saved with .h are the header files and these files cannot contain int main().

int main()
{
    stackUsingLL<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    cout << s.top() << endl;

    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;

    cout << s.getSize() << endl;

    cout << s.isEmpty() << endl;

    return 0;
}