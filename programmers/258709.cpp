#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// 조합 생성 함수
void dfs(vector<vector<int>>& result, vector<int>& temp, int start, int n,
         int k) {
  if (temp.size() == k) {
    result.push_back(temp);
    return;
  }
  for (int i = start; i < n; i++) {
    temp.push_back(i);
    dfs(result, temp, i + 1, n, k);
    temp.pop_back();
  }
}

void getSum(vector<vector<int>>& dice, vector<int>& diceList,
            vector<int>& sumComb, int& sum, int idx, int k) {
  if (idx == k) {
    sumComb.emplace_back(sum);
    return;
  }
  for (int j = 0; j < dice[diceList[idx]].size(); j++) {
    sum += dice[diceList[idx]][j];
    getSum(dice, diceList, sumComb, sum, idx + 1, k);
    sum -= dice[diceList[idx]][j];
  }
}

vector<int> solution(vector<vector<int>> dice) {
  vector<int> answer;
  int max = 0;
  int n = dice.size();
  int k = n / 2;
  vector<vector<int>> diceComb;
  vector<int> temp;
  dfs(diceComb, temp, 0, n, k);
  for (auto d : diceComb) {
    vector<int> sumComb1;
    vector<int> sumComb2;
    vector<int> dInverse;
    // 0~n 에서 d에 포함되지 않은 수를 찾아서 inverseD에 저장
    for (int i = 0; i < n; i++) {
      if (find(d.begin(), d.end(), i) == d.end()) {
        dInverse.push_back(i);
      }
    }

    int sum = 0;
    getSum(dice, d, sumComb1, sum, 0, k);
    sum = 0;
    getSum(dice, dInverse, sumComb2, sum, 0, k);

    sort(sumComb1.begin(), sumComb1.end());
    sort(sumComb2.begin(), sumComb2.end());

    int winCount = 0;
    for (int i = 0; i < sumComb1.size(); i++) {
      int left = 0;
      int right = sumComb2.size() - 1;

      while (left <= right) {
        int mid = (left + right) / 2;

        // 상대방의 케이스를 점차 좁혀나간다.
        if (sumComb1[i] > sumComb2[mid]) {
          left = mid + 1;
        } else {
          right = mid - 1;
        }
      }

      winCount += left;
    }
    if (winCount > max) {
      max = winCount;
      answer = d;
    }
  }

  for (auto i : answer) {
    i++;
  }

  return answer;
}
