#include <iostream>
#include <cstdio>
#include <vector>
#include <memory.h>
#include <queue>
using namespace std;

const int MAX = 1001;
vector <int> graph[MAX];

bool check[MAX];

void BFS(int start){
    queue <int> q;
    q.push(start);
    check[start] = true;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int i = 0; i < graph[cur].size();i++){
            int next = graph[cur][i];
            if(check[next] == false){
                q.push(next);
                check[next] = true;
            }
        }
    }
}

int main(){
    memset(check, 0, sizeof(check));
    int n, m;
    int answer = 0;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    for(int i = 1; i <= n; i++){
        if(check[i] == false){
            BFS(i);
            //cout << i << ' ';
            answer++;
        }
    }
    //cout << '\n';
    cout << answer;
    return 0;
}