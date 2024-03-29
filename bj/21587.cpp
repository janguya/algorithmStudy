#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    int v[100000];
    int result = 0;
    int sum = 0;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        sum += v[i];
    }

    int tmpSum = 0;
    int tmpMax = 0;
    for (int i = 0; i < n - 1; i++)
    {
        tmpSum += v[i];
        if (tmpSum - 2 * v[i] > tmpMax)
        {
            tmpMax = tmpSum - 2 * v[i];
        }
    }
    if (result < sum - v[n - 1] + tmpMax)
    {
        result = sum - v[n - 1] + tmpMax;
    }
    tmpSum = 0;
    tmpMax = 0;
    for (int i = 1; i < n - 1; i++)
    {
        if (v[i] > tmpMax)
        {
            tmpMax = v[i];
        }
    }
    if (result < sum - v[0] - v[n - 1] + tmpMax)
    {
        result = sum - v[0] - v[n - 1] + tmpMax;
    }
    tmpSum = 0;
    tmpMax = 0;
    reverse(&v[0], &v[0] + n);
    for (int i = 0; i < n - 1; i++)
    {
        tmpSum += v[i];
        if (tmpSum - 2 * v[i] > tmpMax)
        {
            tmpMax = tmpSum - 2 * v[i];
        }
    }
    if (result < sum - v[n - 1] + tmpMax)
    {
        result = sum - v[n - 1] + tmpMax;
    }
    cout << result;
}