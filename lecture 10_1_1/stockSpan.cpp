#include <iostream>
using namespace std;
#include <stack>

int *stockSpan(int *price, int size)
{
    // Write your code here

    int *ans = new int[size];
    int j = 0;

    stack<pair<int, int>> st;
    for (int i = 0; i < size; i++)
    {
        int days = 1;

        if (st.empty())
        {
            st.push({price[i], days});
            ans[j] = days;
            j++;
        }
        while (st.top().first < price[i])
        {
            st.push({price[i], days});
            ans[j] = days + st.top().second;
            j++;

            st.pop();
        }
        if (price[i] < st.top().first)
        {
            st.push({price[i], days});
            ans[j] = days;
            j++;
        }
    }
    return ans;
}

int main()
{
    int size;
    cin >> size;

    int *input = new int[size];
    for (int i = 0; i < size; i++)
    {
        cin >> input[i];
    }

    int *output = stockSpan(input, size);
    for (int i = 0; i < size; i++)
    {
        cout << output[i] << " ";
    }

    cout << "\n";

    delete[] input;
    delete[] output;
}