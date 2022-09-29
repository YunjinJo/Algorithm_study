#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;

const int MAX = 51;
int chessBoard[MAX][MAX];
int weight[MAX][MAX];
vector<int> v;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void checkWeight(int startX, int startY, bool color){
    // color = 1 -> white, color = 0 -> black
    memset(weight, 0, sizeof(weight));
    for(int i = startY; i < startY + 8; i++){
        for(int j = startX; j < startX + 8; j++){
            if(chessBoard[i][j] == color){
                weight[i][j] = 1;
            }
            else{
                weight[i][j] = 0;
            }
            color = !color;
        }
        color = !color;
    }
}

int calWeight(int startX, int startY, int n, int m){
    int cnt = 0;
    if(startY + 8 > n || startX + 8 > m) return -1;
    checkWeight(startX, startY, chessBoard[startY][startX]);
    for(int i = startY; i < startY + 8; i++){
        for(int j = startX; j < startX + 8; j++){
            if(weight[i][j] == false) cnt++;
        }
    }
    return min(64-cnt, cnt);
}


int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            char temp;
            temp = cin.get();
            if(temp == '\n')
                temp = cin.get();
            if(temp == 'W'){
                chessBoard[i][j] = 1;
            }
            else{
                chessBoard[i][j] = 0;
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            v.push_back(calWeight(j, i, n, m));
        }
    }
    int minValue = 70;
    for(int i = 0; i < v.size(); i++){
        if(minValue > v[i] && v[i] != -1)
            minValue = v[i];
    }
    cout << minValue;
  return 0;
}