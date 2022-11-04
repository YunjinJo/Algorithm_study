// https://www.acmicpc.net/problem/10026
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <queue>

using  namespace  std;
const int MAX = 102;

int n;
char mapRGB[MAX][MAX];
bool isVisitedRGB[MAX][MAX];

char mapRB[MAX][MAX];
bool isVisitedRB[MAX][MAX];

int dy[] = {0, 0, -1, 1};
int dx[] = {-1, 1, 0,0};

void init(){
    n = 0;
    memset(mapRGB, 0, sizeof(mapRGB));
    memset(isVisitedRGB, 0, sizeof(isVisitedRGB));
    memset(mapRB, 0, sizeof(mapRB));
    memset(isVisitedRB, 0, sizeof(isVisitedRB));
}

void setColorMap(){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> mapRGB[i][j];
            if(mapRGB[i][j] == 'G'){
                mapRB[i][j] = 'R';
            }
            else{
                mapRB[i][j] = mapRGB[i][j];
            }
        }
    }
}

void BFS(int sY, int sX, bool isRGB){
    queue<pair<int, int>> q;
    if(isRGB){
        q.push({sY, sX});
        isVisitedRGB[sY][sX] = true;
    }
    else{
        q.push({sY, sX});
        isVisitedRB[sY][sX] = true;
    }
    while (!q.empty()){
        int curX = q.front().second;
        int curY = q.front().first;
        q.pop();
        for(int i = 0; i < 4; i++){
            int nextX = curX + dx[i];
            int nextY = curY + dy[i];
            if(nextX < 0 || nextX >= n || nextY < 0 || nextY >= n) continue;
            if(isRGB){
                if(!isVisitedRGB[nextY][nextX] && mapRGB[curY][curX] == mapRGB[nextY][nextX]) {
                    q.push({nextY, nextX});
                    isVisitedRGB[nextY][nextX] = true;
                }
            }
            else{
                if(!isVisitedRB[nextY][nextX] && mapRB[curY][curX] == mapRB[nextY][nextX]) {
                    q.push({nextY, nextX});
                    isVisitedRB[nextY][nextX] = true;
                }
            }
        }
    }
}



int checkRGB(){
    int sectionCount = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(!isVisitedRGB[i][j]){
                BFS(i, j, 1);
                sectionCount++;
            }
        }
    }
    return sectionCount;
}

int checkRB(){
    int sectionCount = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(!isVisitedRB[i][j]){
                BFS(i, j, 0);
                sectionCount++;
            }
        }
    }
    return sectionCount;
}



int main() {
    init(); // 초기화
    setColorMap(); // 입력

    int sectionCountRGB = checkRGB();
    int sectionCountRB = checkRB();

    cout << sectionCountRGB << ' ' << sectionCountRB;
    return 0;
}
