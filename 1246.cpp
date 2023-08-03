#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    int sum = 0;
    pair<int, int> result;

    vector<int> v;

    for (int i = 0; i < m; i++)
    {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    sort(v.begin(), v.end(), greater());

    int j = 1;
    for (auto i : v)
    {
        if (j > n)
            break;
        if (i * j >= sum)
        {
            sum = i * j;
            result = make_pair(i, i * j);
        }
        j++;
    }

    cout << result.first << " " << result.second;
}