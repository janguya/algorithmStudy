#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v;
    int first;
    int last;
    int result = 0;
    for (int i = 0; i < n; i++)
    {

        int tmp;
        cin >> tmp;
        if (i == 0)
        {
            first = tmp;
        }
        if (i == n - 1)
        {
            last = tmp;
        }
        v.push_back(tmp);
    }
    for (auto i : v)
    {
        if (i < first)
        {
            first = i;
            result++;
            continue;
        }
        if (i > last)
        {
            last = i;
            result++;
        }
    }
    cout << result;
}