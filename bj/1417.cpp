#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int arr[101];
int result = 0;

bool cycle()
{
    int max = arr[1];
    int indexOfMax = 1;
    for (int i = 2; i <= N; i++)
    {
        if (arr[i] >= max)
        {
            max = arr[i];
            indexOfMax = i;
        }
    }
    if (indexOfMax == 1)
    {
        return false;
    }
    arr[indexOfMax]--;
    arr[1]++;
    result++;
    return true;
}

int main()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
    }

    while (cycle())
    {
    }
    cout << result;
}