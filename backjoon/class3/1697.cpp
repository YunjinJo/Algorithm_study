#include <iostream>
#include <memory.h>
#include <cstdio>
#include <queue>
using namespace std;

struct Pos
{
    int x;
    int cnt;
};


const int MAX = 100001;
int n, k;
int map[MAX];
bool check[MAX];
int answer = 0;


void BFS(int s){
    queue <Pos> q;
    Pos temp;
    temp.x = s;
    temp.cnt = 0;
    q.push(temp);
    check[s] = true;
    while (!q.empty())
    {
        Pos cur = q.front();
        q.pop();
        for(int i = 0; i < 3; i++){
            int next = cur.x;
            if(next < 0 || next >= MAX) continue;
            if(i == 0){
                next = cur.x;
                next *= 2;
            }
            else if(i == 1){
                next = cur.x;
                next++;
            }
            else if(i == 2){
                next = cur.x;
                next--;
            }
            if(check[next] == false){
                Pos nextpos;
                nextpos.x = next;
                nextpos.cnt = cur.cnt + 1;
                q.push(nextpos);
                check[next] = true;
                if(next == k){
                    answer = nextpos.cnt;
                    return;
                }
            }
        }
    }
    
}

int main(){
    memset(check, 0, sizeof(check));
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n >> k;
    BFS(n);
    cout << answer;
    return 0;
}