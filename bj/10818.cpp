#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    int n;
    cin >> n;
    vector<int> v;

    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    
    int max = *max_element(v.begin(), v.end());
    int min = *min_element(v.begin(), v.end());

    cout << min << " " << max;
}