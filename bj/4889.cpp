#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool solve(int t)
{
    string s;

    int sum = 0;
    int result = 0;
    cin >> s;
    if (s[0] == '-')
        return false;
    for (int i = 0; i < s.length(); i++)
    {

        if (s[i] == '{')
        {
            sum++;
        }
        else
        {
            sum--;
        }
        if (sum < 0)
        {
            s[i] = '{';
            sum += 2;
            result++;
        }
    }
    result += sum / 2;
    cout << t << ". " << result << endl;
    return true;
}

int main()
{
    int t = 1;
    while (1)
    {
        if (!solve(t))
            break;
        t++;
    }
    return 0;
}