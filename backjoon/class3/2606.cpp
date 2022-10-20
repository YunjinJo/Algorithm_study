#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <memory.h>
using namespace std;

const int MAX = 200;
int n;
int m;
int answer = 0;
vector <int> graph[MAX];
bool check[MAX];

void BFS(int s){
    queue <int> q;
    q.push(s);
    check[s] = true;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int i = 0; i < graph[cur].size(); i++){
            int next = graph[cur][i];
            if(check[next] == false){
                q.push(next);
                check[next] = true;
                answer++;
            }
        }
    }
}

int main(){
    memset(check, 0, sizeof(check));
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    BFS(1);
    cout << answer;
    return 0;
}