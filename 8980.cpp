#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<pair<int, int>, int> &a, pair<pair<int, int>, int> &b)
{
    if (a.first.second == b.first.second)
    {
        return a.first.first > b.first.first;
    }
    return a.first.second < b.first.second;
}

int main()
{
    int n, c, m;
    vector<pair<pair<int, int>, int>> v;
    int result = 0;

    int town[2001] = {
        0,
    };

    cin >> n >> c >> m;

    for (int i = 0; i < m; i++)
    {
        int tmp1, tmp2, tmp3;
        cin >> tmp1 >> tmp2 >> tmp3;
        if (tmp3 > c)
            tmp3 = c;
        v.push_back(make_pair(make_pair(tmp1, tmp2), tmp3));
    }

    sort(v.begin(), v.end(), cmp);
    // cout << endl;
    // for (auto i : v)
    // {
    //     cout << i.first.first << " " << i.first.second << " " << i.second << endl;
    // }
    // cout << endl;

    for (auto i : v)
    {
        int a = i.second;

        for (int j = i.first.first; j < i.first.second; j++)
        {
            if (c - town[j] < i.second && a > c - town[j])
            {
                a = c - town[j];
            }
        }
        if (a > 0)
        {
            for (int j = i.first.first; j < i.first.second; j++)
            {
                town[j] += a;
            }
            result += a;
        }
    }
    cout << result;
}