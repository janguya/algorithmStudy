#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    char current = ' ';
    int sum = 0;
    int result[4] = {
        0,
    };
    bool first = true;
    for (int i = 0; i < s.length(); i++)
    {
        if (i == 0)
        {
            current = s[i];
            continue;
        }
        if (first)
        {
            if (s[i] == current)
                continue;
            else
            {
                first = false;
            }
        }
        if (s[i] == 'R')
        {
            result[0]++;
        }
        else
        {
            result[1]++;
        }
    }
    first = true;
    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (i == s.length() - 1)
        {
            current = s[i];
            continue;
        }
        if (first)
        {
            if (s[i] == current)
                continue;
            else
            {
                first = false;
            }
        }
        if (s[i] == 'R')
        {
            result[2]++;
        }
        else
        {
            result[3]++;
        }
    }
    sort(result, result + 4);
    cout << result[0];
}