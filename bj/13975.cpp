#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

void solve()
{
    int n;
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    long long sum = 0;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        pq.push(tmp);
    }

    while (1)
    {
        long long tmp1 = pq.top();
        pq.pop();
        long long tmp2 = pq.top();
        pq.pop();
        sum += tmp1 + tmp2;
        if (pq.empty())
        {
            break;
        }
        pq.push(tmp1 + tmp2);
    }
    cout << sum;
}

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        solve();
        cout << endl;
    }
}