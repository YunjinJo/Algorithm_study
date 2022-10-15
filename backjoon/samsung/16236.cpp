#include <iostream>
#include <cstdio>
#include <queue>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 22;
int n;
int m = 0; // 물고기 마리수
int sea[MAX][MAX];

int dx[] = {0, -1, 1, 0};
int dy[] = {-1, 0, 0, 1};

int sharkSize = 2;
int growCnt = 0;
int currentX = 0;
int currentY = 0;

bool isOut(int X, int Y){
    if(X < 0 || X >= n || Y <0 || Y >= n) return true;
    else return false;
}

int BFS(){
    int cnt = 0;
    queue <pair<int, int>> q;
    bool check[MAX][MAX] = {0, };
    q.push(make_pair(currentX, currentY));
    check[currentY][currentX] = true;
    

    while(!q.empty()){
        int topX = q.front().first;
        int topY = q.front().second;
        if(sea[topY][topX] < sharkSize && sea[topY][topX] != 0){
            int subX = abs(currentX - topX);
            int subY = abs(currentY - topY);
            int distance = subX + subY;
        }
        //cout << sea[topY][topX] << ' ';
        q.pop();

        for(int i = 0; i < 4; i++){
            int nextX = topX + dx[i];
            int nextY = topY + dy[i];
            if(isOut(nextX, nextY)) continue;

            if(check[nextY][nextX] == 0){
                if(sea[nextY][nextX] <= sharkSize){
                    q.push(make_pair(nextX, nextY));
                    check[nextY][nextX] = true;
                }

            }

        }
        
    }
    
    return cnt;
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int temp;
            cin >> temp;
            if(temp == 9){
                currentX = j;
                currentY = i;
            }
            else m++;
            sea[i][j] = temp;
        }
    }
    int answer = 0;
    while(true){
        int temp = BFS();
        if(temp == 0){
            break;
        }
        else{
            answer += temp;
            growCnt++;
            if(growCnt == sharkSize){
                sharkSize++;
                growCnt = 0;
            }
        }
    }
    cout << answer;
    return 0;
}