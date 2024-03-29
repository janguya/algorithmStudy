#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int T;
    vector<int> v;

    cin >> T;

    for (int i = 0; i < T; i++)
    {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    for (int i = 0; i < T; i++)
    {
        vector<int> result;
        int n = v[i];
        int j = 0;

        while (n > 0)
        {
            if (n % 2 == 1)
            {
                result.push_back(j);
            }
            n /= 2;
            j++;
        }
        for (int k = 0; k < result.size(); k++)
        {
            cout << result[k] << " ";
        }
        cout << endl;
    }
}