#include <cstdio>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <vector>
#include <cstdlib>
using namespace std;

const int MAX = 22;

int arr[MAX][MAX];
bool check[101];

// 좌 우 하 상
// 0  1  2  3
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int t;
int n;

int findway[4]; // 탐색할 방향

void getWay(int y, int x){
  vector<pair<int, int>> v;
  for(int i = 0; i < 4; i++){
    v.push_back(make_pair(arr[y+dy[i]][x+dx[i]], i));
  }
  sort(v.begin(), v.end(), greater<>());
  for(int i = 0; i < 4; i++){
    findway[i] = v[i].second;
  }
}

int getAnswer(int y, int x){
  int cnt = 1;
  int total = arr[y][x];
  memset(check, 0, sizeof(check));
  check[total] = 1;
  getWay(y, x);
  while(cnt < n){
    for(int i = 0; i < 4; i++){
      int yCord = y + dy[findway[i]] * cnt;
      int xCord = x + dx[findway[i]] * cnt;
      int protein = arr[yCord][xCord];
      if(yCord < 0 || yCord > n-1 || xCord < 0 || yCord > n-1) continue;
      if(check[protein] == 1) continue;
      total += protein;
      check[protein] = 1;
    }
    cnt++;
  }
  return total;
}

int getSearch(){
  int maxValue;
  int answer = 0;
  for(int i = 1; i < n-1; i++){
    for(int j = 1; j < n-1; j++){
      maxValue = getAnswer(i, j);
      if(answer < maxValue) answer = maxValue;
    }
  }
  return answer;
}

int main() {

  cin >> t;
  for(int testcase = 1; testcase <= t; testcase++){
    memset(arr, 0, sizeof(arr));
    cin >> n;
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        int temp;
        cin >> temp;
        arr[i][j] = temp;
      }
    }
    int tempAnswer = getSearch();
    cout << '#' << testcase << ' ';
    cout << tempAnswer << '\n';
  }
  
  

  return 0;
}