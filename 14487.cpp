#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    vector<int> v;
    int result = 0;

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
        result += v[i];
    }
    cout << result;
}