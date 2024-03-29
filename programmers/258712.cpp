#include <string>
#include <vector>

using namespace std;

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// 선물 횟수를 저장할 이차원 배열을 생성하는 함수
vector<vector<int>> createGiftMatrix(const vector<string>& friends, const vector<string>& gifts) {
    unordered_map<string, unordered_map<string, int>> giftMap;

    // 각 친구들이 서로에게 선물을 주고 받은 횟수 계산
    for(const string& gift : gifts) {
        size_t space_pos = gift.find(' ');
        string giver = gift.substr(0, space_pos);
        string receiver = gift.substr(space_pos + 1);
        giftMap[giver][receiver]++;
    }

    // 이차원 배열 생성
    vector<vector<int>> giftMatrix(friends.size(), vector<int>(friends.size(), 0));

    // 이차원 배열에 선물 횟수 입력
    for(int i = 0; i < friends.size(); ++i) {
        for(int j = 0; j < friends.size(); ++j) {
            giftMatrix[i][j] = giftMap[friends[i]][friends[j]];
        }
    }

    return giftMatrix;
}


int solution(vector<string> friends, vector<string> gifts) {
    vector<vector<int>> giftMatrix = createGiftMatrix(friends, gifts);
    vector<int> giftPoint(friends.size(), 0);
    vector<int> giftCount(friends.size(), 0);
    for(int i = 0; i < friends.size(); ++i) {
        for(int j = 0; j < friends.size(); ++j) {
            giftPoint[i] += giftMatrix[i][j];
            giftPoint[i] -= giftMatrix[j][i];
        }
    }
    for(int i = 0; i < friends.size(); ++i) {
        for(int j = 0; j < friends.size(); ++j) {
            if(i == j) continue;
            if(giftMatrix[i][j] == giftMatrix[j][i]){
              if(giftPoint[i] > giftPoint[j]){
                giftCount[i]++;
              }
              else{
                continue;
              }
            }
            else{
              if(giftMatrix[i][j] > giftMatrix[j][i]){
                giftCount[i]++;
              }
         
            }
        }
    }
    for(auto i : giftCount){
        cout << i << endl;
    }
    auto maxIter = max_element(giftCount.begin(), giftCount.end());
    int max = *maxIter;
    return max;

 
}