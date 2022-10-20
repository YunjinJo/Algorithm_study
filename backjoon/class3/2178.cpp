#include <iostream>
#include <cstdio>
#include <queue>
#include <memory.h>
#include <string>
using namespace std;
struct Pos
{
    int y, x;
    int cnt;
};


const int MAX = 101;
int n, m;
int arr[MAX][MAX];
bool check[MAX][MAX];

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

Pos answer;

void BFS(int sy, int sx){
    queue <Pos> q;
    Pos temp;
    temp.y = sy;
    temp.x = sx;
    temp.cnt = 1;

    q.push(temp);
    check[sy][sx] = true;
    while (!q.empty())
    {
        Pos cur = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            int nextY = cur.y + dy[i];
            int nextX = cur.x + dx[i];
            if(nextX < 0 || nextY < 0 || nextX >= m || nextY >= n) continue;
            if(check[nextY][nextX] == false){
                Pos next;
                next.y = nextY;
                next.x = nextX;
                next.cnt = cur.cnt + 1;
                q.push(next);
                check[nextY][nextX] = true;
                if(nextY == n-1 && nextX == m-1){
                    answer.y = next.y;
                    answer.x = next.x;
                    answer.cnt = next.cnt;
                }
            }
        }
    }
    
}

int main(){
    memset(check, 0, sizeof(check));
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        string temp;
        cin >> temp;
        for(int j = 0; j < m; j++){
            
            if(temp[j] == '0'){
                check[i][j] = true;
                arr[i][j] = 0;
            }
            else{
                arr[i][j] = 1;
            }
            
        }
    }

    BFS(0,0);
    cout << answer.cnt;
    return 0;
}