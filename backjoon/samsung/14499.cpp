#include<iostream>
#include <cstdio>
#include <vector>
using namespace std;

const int MAX = 22;
const int opMAX = 1001;
int n, m, x, y, k;
int board[MAX][MAX];
int operation[opMAX]; // 1 동, 2 서, 3 북, 4 남
int dx[] = {0, 1, -1, 0, 0};
int dy[] = {0, 0, 0, -1, 1};
int dice[6] = {0, };

void changeDicePos(int dir){
    int temp;
    temp = dice[0];
    if(dir == 1){
        dice[0] = dice[3];
        dice[3] = dice[5];
        dice[5] = dice[2];
        dice[2] = temp;
    }
    else if(dir == 2){
        dice[0] = dice[2];
        dice[2] = dice[5];
        dice[5] = dice[3];
        dice[3] = temp;
    }
    else if(dir == 3){
        dice[0] = dice[1];
        dice[1] = dice[5];
        dice[5] = dice[4];
        dice[4] = temp;
    }
    else if(dir == 4){
        dice[0] = dice[4];
        dice[4] = dice[5];
        dice[5] = dice[1];
        dice[1] = temp;
    }

}

bool isOut(int X, int Y){
    if(X < 0 || X >= m || Y < 0 || Y >= n) return true;
    else return false;
}

void moveDice(int dirIndex){
    int dir = operation[dirIndex];
    int nextX = x + dx[dir];
    int nextY = y + dy[dir];
    if(isOut(nextX, nextY)) return;
    if(board[nextY][nextX] == 0){
        board[nextY][nextX] = dice[5];
    }
    else{
        dice[5] = board[nextY][nextX];
        board[nextY][nextX] = 0;
    }
    for(int i = 0; i < 6; i++){
        cout << dice[i] << ' ';
    }
    cout << '\n';
    cout << dice[0] << '\n';
    changeDicePos(dir);
    x = nextX;
    y = nextY;
    
    
}

void Simulation(){
    for(int i = 0; i < k; i++){
        moveDice(i);
    }
}

int main(){
    cin >> n >> m >> x >> y >> k;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> board[i][j];
        }
    }
    for(int i = 0; i < k; i++){
        cin >> operation[i];
    }

    Simulation();
    return 0;
}