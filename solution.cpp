//
// Created by Kylian Lee on 2021/08/05.
//

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

vector<vector<int>> cache;
vector<pair<int, int>> study_list;

void solution(int chapter, int entire_time);

int main(){
  int chapter, entire_time;
  cin >> chapter >> entire_time;
  cache.resize(chapter + 1);
  for (int i = 0; i < chapter + 1; ++i) {
    cache[i].resize(entire_time + 1, 0);
  }
  study_list.emplace_back(0, 0);
  for (int i = 0; i < chapter; ++i) {
    int study_time, score;
    cin >> study_time >> score;
    study_list.emplace_back(study_time, score);
  }
//  for (int i = 0; i < chapter; ++i) {   //  출력
//    cout << study_list[i].first << study_list[i].second << endl;
//  }
  solution(chapter, entire_time);
  cout << cache[chapter][entire_time] << endl;
  return 0;
}

void solution(int chapter, int entire_time){
  for (int i = 1; i <= chapter; ++i) {
    for (int j = 1; j <= entire_time; ++j) {
      if(study_list[i].first > j)
        cache[i][j] = cache[i - 1][j];
      else
        cache[i][j] = max(cache[i - 1][j], cache[i - 1][j - study_list[i].first] + study_list[i].second);
    }
  }
}