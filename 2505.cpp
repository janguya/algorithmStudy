#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;

int main()
{
    int N;
    int count = 0;
    vector<int> resultR;
    vector<int> resultL;

    v.push_back(0);

    cin >> N;
    int i;
    for (i = 1; i <= N; i++)
    {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    vector<int> v2 = v;

    for (int j = 1; j <= N; j++)
    {
        if (v2[j] != j)
        {
            vector<int>::iterator it;
            it = find(v2.begin(), v2.end(), j);
            reverse(v2.begin() + j, it + 1);
            resultR.push_back(j);
            resultR.push_back(it - v2.begin());
            count++;
        }
    }
    if (count > 2)
    {
        int count2 = 0;
        {
            for (int j = N; j > 0; j--)
            {
                if (v[j] != j)
                {
                    vector<int>::iterator it;
                    it = find(v.begin(), v.end(), j);
                    reverse(it, v.begin() + j + 1);
                    resultL.push_back(j);
                    resultL.push_back(it - v.begin());
                    count2++;
                }
            }
        }
        if (count2 == 0)
        {
            cout << "1 1" << endl
                 << "1 1";
            return 0;
        }
        if (count == 1)
        {
            cout << "1 1" << endl
                 << resultL[1] << " " << resultL[0];
            return 0;
        }
        else
        {
            cout << resultL[1] << " " << resultL[0] << endl
                 << resultL[3] << " " << resultL[2];
            return 0;
        }
    }
    else
    {
        if (count == 0)
        {
            cout << "1 1" << endl
                 << "1 1";
            return 0;
        }
        if (count == 1)
        {
            cout << "1 1" << endl
                 << resultR[0] << " " << resultR[1];
            return 0;
        }
        else
        {
            cout << resultR[0] << " " << resultR[1] << endl
                 << resultR[2] << " " << resultR[3];
            return 0;
        }
    }
}