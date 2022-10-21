#include <iostream>
#include <cstdio>
#include <memory.h>
#include <queue>
#include <algorithm>
using namespace std;

struct Tomato
{
    int x, y, h, cnt;
};

const int MAX = 101;
queue<Tomato> q;
bool check[MAX][MAX][MAX];
int arr[MAX][MAX][MAX];

int m, n, h;

int dy[] = {-1, 1, 0, 0, 0, 0};
int dx[] = {0, 0, -1, 1, 0, 0};
int dh[] = {0, 0 ,0, 0, -1, 1};
int answer = 0;

bool isOut(Tomato in){
    if(in.x < 0 || in.x >= m) return true;
    else if(in.y < 0 || in.y >= n) return true;
    else if(in.h < 0 || in.h >= h) return true;
    return false;
}

void BFS(){
    while(!q.empty()){
        Tomato cur = q.front();
        answer = max(answer, cur.cnt);
        q.pop();
        for(int i = 0; i < 6; i++){
            Tomato next;
            next.y = cur.y + dy[i];
            next.x = cur.x + dx[i];
            next.h = cur.h + dh[i];
            next.cnt = cur.cnt + 1;
            if(isOut(next)) continue;
            if(check[next.h][next.y][next.x] == false){
                q.push(next);
                check[next.h][next.y][next.x] = true;
            }
        }
    }
}


int main(){
    memset(check, 0, sizeof(check));
    int temp;
    Tomato input;
    cin >> m >> n >> h;
    for(int height = 0; height < h; height++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> temp;
                if(temp == 1){
                    input.h = height;
                    input.y = i;
                    input.x = j;
                    input.cnt = 0;
                    q.push(input);
                    check[height][i][j] = true;
                }
                else if(temp == -1){
                    check[height][i][j] = true;
                }
                arr[height][i][j] = temp;
            }
        }
    }
    BFS();
    for(int height = 0; height < h; height++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(check[height][i][j] == false){
                    cout << "-1\n";
                    return 0;
                }
            }
        }
    }

    cout << answer;


    return 0;
}