#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int l, r;
    int result = 0;

    cin >> l >> r;
    int val = 1000000000;
    while (1)
    {
        if (val == 0)
            break;
        if (l < val && r < val)
        {
            val /= 10;
            continue;
        }
        else
        {
            if (l / val == r / val)
            {
                if (l / val == 8 && r / val == 8)
                {
                    result++;
                }
                l -= ((l / val) * val);
                r -= ((r / val) * val);
                val /= 10;
                continue;
            }
        }
        break;
    }
    cout << result;
}