#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    int arr[11] = {0,};
    
    for (int i = 1; i < 11; i++)
    {
        int a, b;
        cin >> a >> b;
        arr[i] = arr[i-1] + b - a;
    }

    int max = *max_element(begin(arr), end(arr));
    
    cout << max;
    
}