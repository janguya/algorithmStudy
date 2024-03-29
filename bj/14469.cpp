#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    vector<pair<int, int>> v;
    int time = 0;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        v.push_back(make_pair(tmp1, tmp2));
    }

    sort(v.begin(), v.begin() + n);

    for (auto i : v)
    {
        if (i.first > time)
        {
            time = i.first + i.second;
        }
        else
        {
            time += i.second;
        }
    }

    cout << time;
}