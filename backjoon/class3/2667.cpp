#include <iostream>
#include <cstdio>
#include <memory.h>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Pos
{
  int y, x;
};


const int MAX = 26;
int n;
int arr[MAX][MAX];
bool check[MAX][MAX];

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};
vector <int> answer;

void show(){
  cout << '\n';
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cout << check[i][j] << ' ';
    }
    cout << '\n';
  }
}

void BFS(int y, int x){
  int house_cnt = 0;
  Pos temp;
  queue <Pos> q;
  temp.y = y;
  temp.x = x;
  q.push(temp);
  check[y][x] = true;
  house_cnt++;
  while(!q.empty()){
    Pos cur = q.front();
    q.pop();
    for(int dir = 0; dir < 4; dir++){
      Pos next;
      next.y = cur.y + dy[dir];
      next.x = cur.x + dx[dir];
      if(next.x < 0 || next.y < 0 || next.x >= n || next.y >= n) continue;
      if(check[next.y][next.x] == false){
        q.push(next);
        check[next.y][next.x] = true;
        house_cnt++;
      }
    }
  }
  answer.push_back(house_cnt);
}


int main(){
  memset(check, 0, sizeof(check));
  cin >> n;
  for(int i = 0; i < n; i++){
    string temp;
    cin >> temp;
    for(int j = 0; j < n; j++){
        if(temp[j] == '0'){
          check[i][j] = true;
          arr[i][j] = 0;
        }
        else{
          arr[i][j] = 1;
        }
    }
  }
  //show();
  
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
        if(check[i][j] == 0){
          BFS(i, j);
        }
    }
  }
  int vSize = answer.size();
  sort(answer.begin(), answer.end());
  cout << vSize << '\n';
  for(int i = 0; i < vSize; i++){
    cout << answer[i] << '\n';
  }
  
  return 0;
}