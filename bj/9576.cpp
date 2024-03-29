#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool cmp(pair<int, int> &a, pair<int, int> &b)
{
    return a.second < b.second;
}

void solve()
{
    int N, M;
    int isGave[1001] = {
        0,
    };
    int count = 0;
    cin >> N >> M;
    vector<pair<int, int>> v;
    for (int i = 0; i < M; i++)
    {
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        v.push_back(make_pair(tmp1, tmp2));
    }
    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = v[i].first; j <= v[i].second; j++)
        {
            if (!isGave[j])
            {
                isGave[j] = 1;
                count++;
                break;
            }
        }
    }
    cout << count << endl;
}

int main()
{
    int TC;

    cin >> TC;

    for (int i = 0; i < TC; i++)
    {
        solve();
    }
}