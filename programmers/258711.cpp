#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class node {
  public:
  int node; // 점
  int inCount; // 들어오는 간선 수
  int outCount; // 나가는 간선 수
};

vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer(4,0);
    unordered_map<int, node> nodes;
    int graphCount = 0;
    for (auto edge : edges) {
        if (nodes.find(edge[0]) == nodes.end()) {
            nodes[edge[0]] = {edge[0], 0, 0};
        }
        if (nodes.find(edge[1]) == nodes.end()) {
            nodes[edge[1]] = {edge[1], 0, 0};
        }
        nodes[edge[0]].outCount++;
        nodes[edge[1]].inCount++;
    }
    for(auto n : nodes){
        if(n.second.inCount == 0 && n.second.outCount >= 2){
          graphCount += n.second.outCount;
            nodes.erase(n.first);
            answer[0] = n.first;
            break;
        }
    }
    
    for(auto e : edges){
      if(e[0] == answer[0]){
        nodes[e[1]].inCount--;
      }
    }

    for(auto n : nodes){
    cout << n.second.inCount << n.second.outCount << endl;
      // 막대그래프 마지막점 찾기
      if(n.second.outCount == 0){
        answer[2]++;
        continue;
      }
      if(n.second.inCount == 2 && n.second.outCount == 2){
        answer[3]++;
      }
    }
    answer[1] = graphCount - answer[2] - answer[3];
    
    return answer;
}