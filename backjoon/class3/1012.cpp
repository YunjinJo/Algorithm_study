#include <iostream>
#include <cstdio>
#include <memory.h>
#include <queue>
using namespace std;
const int MAX = 51;
bool arr[MAX][MAX];
bool check[MAX][MAX];
int t, n, m, k;

int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};

void BFS(int y, int x){
    queue <pair<int, int>> q;
    q.push(make_pair(y, x));
    check[y][x] = 1;
    int frontX, frontY;
    while (!q.empty())
    {
        frontX = q.front().second;
        frontY = q.front().first;
        q.pop();
        for(int i = 0; i < 4; i++){
            int moveX = frontX + dx[i];
            int moveY = frontY + dy[i];
            if(moveX < 0 || moveX >= m || moveY < 0 || moveY >= n) continue;
            if(arr[moveY][moveX]){
                if(check[moveY][moveX] == false){
                    q.push(make_pair(moveY, moveX));
                    check[moveY][moveX] = 1;
                }
            }
        }
    }
    
}

int getResult(){
    int answer = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(arr[i][j] == 1 && check[i][j] == 0){
                //cout << j << ' ' << i << '\n';
                BFS(i, j);
                answer++;
            }
        }
    }

    return answer;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int x, y;
    cin >> t;
    for(int testcase = 0; testcase < t; testcase++){
        memset(arr, 0, sizeof(arr));
        memset(check, 0, sizeof(check));
        cin >> m >> n >> k;
        for(int i = 0; i < k; i++){
            cin >> x >> y;
            arr[y][x] = 1;
        }
        cout << getResult() << '\n';
    }
    return 0;
}