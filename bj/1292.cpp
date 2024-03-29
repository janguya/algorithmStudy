#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int arr[1001];

    int j = 0;
    int k = 1;

    for (int i = 1; i < 1001; i++)
    {
        arr[i] = k;
        j++;
        if(j == k){
            j = 0;
            k++;
        }
    }

    int sum = 0;

    int a, b;
    cin >> a >> b;

    for (int i = a; i <= b; i++)
    {
        sum+=arr[i];
    }
    
    cout << sum;
}