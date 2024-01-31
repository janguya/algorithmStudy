#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

bool isPrimeNum(int n) {
  for (int i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) return false;
  }
  return true;
}

int main() {
  int n;
  cin >> n;

  // 한자리는 그냥 설정
  vector<int> v = {2, 3, 5, 7};

  // 두자리 부터
  for (int i = 2; i <= n; i++) {
    vector<int> tmpV;
    for (int j = 0; j < v.size(); j++) {
      for (int i = 1; i < 10; i++) {
        // 뒷자리 0 이나 5면 절대아님
        if (i == 5) continue;
        int k = v[j] * 10 + i;
        if (isPrimeNum(k)) {
          tmpV.push_back(k);
        }
      }
    }
    v = tmpV;
  }

  for (auto i : v) {
    cout << i << endl;
  }
}