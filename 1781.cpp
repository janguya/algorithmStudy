#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct pqCompare
{
    bool operator()(pair<int, int> &a, pair<int, int> &b)
    {
        return a.second > b.second;
    }
};

bool compare(pair<int, int> &a, pair<int, int> &b)
{
    if (a.first == b.first)
    {
        return a.second < b.second;
    }
    return a.first < b.first;
}

int main()
{
    int N;
    vector<pair<int, int>> v;
    priority_queue<int, vector<int>, less<int>> pq;

    int result = 0;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        v.push_back(make_pair(tmp1, tmp2));
    }
    sort(v.begin(), v.end(), compare);
    int time = v.back().first;

    int i = N - 1;
    while (time > 0 && i >= 0)
    {
        if (time > v[i].first)
        {
            if (!pq.empty())
            {
                result += pq.top();
                pq.pop();
            }
            time--;
        }
        else
        {
            pq.push(v[i].second);
            i--;
        }
        cout << result << endl;
    }

    while (time > 0 && !pq.empty())
    {
        result += pq.top();
        pq.pop();
        time--;
    }

    cout << result;
}