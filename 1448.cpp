#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    vector<int> v;

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.begin() + N, greater<int>());
    for (int i = 1; i < N; i++)
    {
        if (i == N - 1)
        {
            cout << -1;
            return 0;
        }
        if (v[i - 1] < v[i] + v[i + 1])
        {
            cout << v[i - 1] + v[i] + v[i + 1];
            return 0;
        }
    }
}