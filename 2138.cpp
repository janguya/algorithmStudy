#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int first[100000] = {
        0,
    },
        second[1000000] = {
            0,
        };
    int N;
    int firstCount = 0;
    int secondCount = 0;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        scanf("%1d", &first[i]);
    }
    for (int i = 0; i < N; i++)
    {
        scanf("%1d", &second[i]);
    }

    int tmp[100000];
    copy(begin(first), end(first), begin(tmp));

    tmp[0] = !tmp[0];
    tmp[1] = !tmp[1];
    firstCount++;
    for (int i = 1; i < N; i++)
    {
        if (tmp[i - 1] != second[i - 1])
        {
            if (i != N - 1)
            {
                tmp[i - 1] = !tmp[i - 1];
                tmp[i] = !tmp[i];
                tmp[i + 1] = !tmp[i + 1];
            }
            else
            {
                tmp[i - 1] = !tmp[i - 1];
                tmp[i] = !tmp[i];
            }
            firstCount++;
        }
    }
    if (!equal(tmp, tmp + N, second))
    {
        firstCount = -1;
    }

    copy(begin(first), end(first), begin(tmp));
    for (int i = 1; i < N; i++)
    {
        if (tmp[i - 1] != second[i - 1])
        {
            if (i != N - 1)
            {
                tmp[i - 1] = !tmp[i - 1];
                tmp[i] = !tmp[i];
                tmp[i + 1] = !tmp[i + 1];
            }
            else
            {
                tmp[i - 1] = !tmp[i - 1];
                tmp[i] = !tmp[i];
            }
            secondCount++;
        }
    }
    if (!equal(tmp, tmp + N, second))
    {
        secondCount = -1;
    }

    if (firstCount == -1 && secondCount == -1)
    {
        cout << -1;
    }
    else
    {
        if (firstCount == -1)
        {
            cout << secondCount;
        }
        else if (secondCount == -1)
        {
            cout << firstCount;
        }
        else
        {
            cout << min(firstCount, secondCount);
        }
    }
}
