#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, k;
    vector<int> v;
    int result = 0;
    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    vector<int> v2;

    for (int i = 0; i < v.size() - 1; i++)
    {
        v2.push_back(v[i + 1] - v[i]);
    }

    sort(v2.begin(), v2.end());

    for (int i = 0; i < n - k; i++)
    {
        result += v2[i];
    }

    cout << result;

    return 0;
}