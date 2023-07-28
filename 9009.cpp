#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> fib;

void solve(int n)
{

    vector<int> v;

    int i = fib.size() - 1;

    while (0 != n)
    {
        if (fib[i] <= n)
        {
            n -= fib[i];
            v.push_back(fib[i]);
        }
        i--;
    }
    reverse(v.begin(), v.end());
    for (auto i : v)
    {
        cout << i << " ";
    }
}

int main()
{
    fib.push_back(0);
    fib.push_back(1);

    while (fib[fib.size() - 1] + fib[fib.size() - 2] <= 1000000000)
    {
        fib.push_back(fib[fib.size() - 1] + fib[fib.size() - 2]);
    }

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        solve(n);
        cout << endl;
    }
}