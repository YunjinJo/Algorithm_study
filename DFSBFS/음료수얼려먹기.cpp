// n x m
// 0 : 구멍 뚫림
// 1 : 칸막이
// 상하좌우중 붙어있으면 연결됨
// 총 생성되는 아이스크림 수

#include <iostream>


using namespace std;

const int MAX = 1005;
int n, m;
int icetray[MAX][MAX];

bool DFS(int x, int y){
    // 범위 벗어남
    if(x <= -1 || x >= n || y <= -1 || y >= m){
        return false;
    }
    
    // 아직 체크하지 않은 노드
    if(icetray[x][y] == false){
        icetray[x][y] = true;
        DFS(x - 1, y);
        DFS(x, y - 1);
        DFS(x + 1, y);
        DFS(x, y + 1);
        return true;
    }
    return false;
}

int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%1d", &icetray[i][j]);
        }
    }
    int result = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(DFS(i, j)){
                result++;
            }
        }
    }
    cout << result;
    return 0;
}
