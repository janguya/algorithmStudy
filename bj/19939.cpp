#include <iostream>

using namespace std;

int main()
{
    int N, K;

    cin >> N >> K;

    int sum = (K * (K + 1)) / 2;

    if (sum > N)
    {
        cout << -1;
        return 0;
    }

    int a = 0;

    if ((N - sum) % K > 0)
    {
        a = 1;
    }

    cout << a + K - 1;
}