#include <iostream>
using namespace std;
#include <sys/time.h>

long getTimeinMicroSeconds()
{
    struct timeval start;
    gettimeofday(&start, NULL);
    return start.tv_sec * 1000000 + start.tv_usec;
}

int fib(int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }
    return fib(n - 1) + fib(n - 2);
}

int main()
{
    int n;
    cin >> n;
    long starttime, endtime;
    starttime = getTimeinMicroSeconds();
    int ans = fib(n);
    endtime = getTimeinMicroSeconds();
    cout << ans << endl;

    cout << "FIBONACCI  " << n << " time = " << endtime - starttime << endl;
    return 0;
}