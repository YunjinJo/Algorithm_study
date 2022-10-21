#include <iostream>
#include <cstdio>
#include <queue>
#include <memory.h>
#include <algorithm>
using namespace std;

struct tomato
{
    int x, y, cnt;
};


const int MAX = 1001;

int m, n;
int arr[MAX][MAX];
bool check[MAX][MAX];
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};
int answer = 0;
queue <tomato> q;

void show(){
    cout << '\n';
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << check[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';

}

void BFS(){

    while(!q.empty()){
        tomato cur = q.front();
        answer = max(answer, cur.cnt);
        q.pop();
        for(int i = 0; i < 4; i++){
            tomato next;
            next.x = cur.x + dx[i];
            next.y = cur.y + dy[i];
            next.cnt = cur.cnt + 1;
            if(next.x < 0 || next.y < 0 || next.x >= m || next.y >= n) continue;
            if(arr[next.y][next.x] == -1) continue;
            if(check[next.y][next.x] == false){
                q.push(next);
                check[next.y][next.x] = true;
                
            }
        }
    }
}

int main(){
    memset(check, 0, sizeof(check));
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> m >> n;
    tomato initTomato;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int temp;
            cin >> temp;
            if(temp == -1){
                check[i][j] = true;
            }
            if(temp == 1){
                initTomato.y = i;
                initTomato.x = j;
                initTomato.cnt = 0;
                q.push(initTomato);
                check[i][j] = true;
            }
            arr[i][j] = temp;
        }
    }
    
    BFS();
    //show();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(check[i][j] == false){
                cout << "-1\n";
                return 0;
            }
        }
    }
    cout << answer;
    return 0;
}