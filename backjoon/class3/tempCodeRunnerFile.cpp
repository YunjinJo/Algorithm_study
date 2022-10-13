#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <memory.h>
using namespace std;

const int MAX = 10001;
int n, m, v;
vector<int> graph[MAX];
bool color[MAX];

void BFS(int s){
    queue<int> q;
    bool check[MAX] = {0, };
    check[s] = true;
    q.push(s);
    while(!q.empty()){
        int current = q.front();
        q.pop();
        cout << current << ' ';
        for(int i = 0; i < graph[current].size(); i++){
            int next = graph[current][i];
            if(!check[next]){
                check[next] = true;
                q.push(next);
            }
        }
    }
}

void DFS(int x){
    
    color[x] = true;
    cout << x << ' ';
    for(int i = 0; i < graph[x].size(); i++){
        int next = graph[x][i];
        if(!color[next]){
            DFS(next);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m >> v;

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i  = 0; i < n; i++){
        sort(graph[i].begin(), graph[i].end());
    }
    DFS(v);
    
    cout << '\n';
    BFS(v);


    return 0;
}