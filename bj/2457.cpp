#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

pair<pair<int, int>, pair<int, int>> arr[100001];

bool compare(pair<pair<int, int>, pair<int, int>> &a, pair<pair<int, int>, pair<int, int>> &b)
{
    if (a.first.first == b.first.first && a.first.second == b.first.second)
    {
        return a.second < b.second;
    }
    else
    {
        return a.first < b.first;
    }
}

bool isLinkable(pair<int, int> &date, pair<pair<int, int>, pair<int, int>> &dateRange)
{
    if (date.first > dateRange.first.first || (date.first == dateRange.first.first && date.second >= dateRange.first.second))
    {
        if (date.first < dateRange.second.first || (date.first == dateRange.second.first && date.second < dateRange.second.second))
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int N;
    cin >> N;

    pair<int, int> date = make_pair(3, 1);
    int count = 0;

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i].first.first >> arr[i].first.second >> arr[i].second.first >> arr[i].second.second;
    }
    sort(arr, arr + N, compare);

    // cout << endl;
    // for (int i = 0; i < N; i++)
    // {
    //     cout << arr[i].first.first << " " << arr[i].first.second << " " << arr[i].second.first << " " << arr[i].second.second << endl;
    // }

    pair<int, int> date2 = date;
    for (int i = 0; i < N; i++)
    {
        if (date2 > make_pair(11, 30))
        {
            break;
        }
        if (isLinkable(date, arr[i]))
        {
            if (date2 < make_pair(arr[i].second.first, arr[i].second.second))
                date2 = make_pair(arr[i].second.first, arr[i].second.second);
        }
        else
        {
            if (date2 < arr[i].first)
            {
                cout << 0;
                return 0;
            }

            if (date2 >= arr[i].second)
            {
                continue;
            }

            if (date2 == make_pair(3, 1))
            {
                continue;
            }

            else
            {
                date = date2;

                if (isLinkable(date, arr[i]))
                {
                    if (date2 < make_pair(arr[i].second.first, arr[i].second.second))
                        date2 = make_pair(arr[i].second.first, arr[i].second.second);
                }
                count++;
            }
        }
        // cout << date2.first << " " << date2.second << " " << count << endl;
    }
    if (date2 > make_pair(11, 30))
    {
        count++;
    }
    else
    {
        cout << 0;
        return 0;
    }

    cout << count;
}