#include <iostream>
#include <cstdio>
#include <deque>
using namespace std;

const int MAX = 102;

int boardSize;
int appleCnt;
int board[MAX][MAX];

int rotationCnt;
int rotationTime[MAX];
char roationWay[MAX];

// 오 -> (L -1 위) (D +1 아래)
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int currentWay = 0;

deque <pair<int, int> > snake; // 시작과 끝 Y, X 좌표

void debugPrint(){
    for(int i = 0; i <= boardSize; i++){
        for(int j = 0; j <= boardSize; j++){
            cout << board[i][j];
        }
        cout << '\n';
    }
    cout << '\n';
}

void checkWay(int rotationIndex){
    char temp = roationWay[rotationIndex];
    if(temp == 'D'){
        if(currentWay == 3) currentWay = 0;
        else currentWay++;
    }
    else if(temp == 'L'){
        if(currentWay == 0) currentWay = 3;
        else currentWay--;
    }
}

bool isOut(){
    int headY = snake.front().first;
    int headX = snake.front().second;

    int nextY = headY + dy[currentWay];
    int nextX = headX + dx[currentWay];

    if(nextX < 1 || nextX > boardSize || nextY < 1 || nextY > boardSize) return true;
    if(board[nextY][nextX] == 1) return true;
    else return false;
}

void move(){
    int headY = snake.front().first;
    int headX = snake.front().second;

    int nextY = headY + dy[currentWay];
    int nextX = headX + dx[currentWay];

    // 사과
    if(board[nextY][nextX] == 2){
        board[nextY][nextX] = 1;
        snake.push_front(make_pair(nextY, nextX));
    }

    else{
        board[nextY][nextX] = 1;
        board[snake.back().first][snake.back().second] = 0;
        snake.push_front(make_pair(nextY, nextX));
        snake.pop_back();
    }

}

int Simulation(){
    int timer = 0;
    int rotationIndex = 0;
    bool flag = true;
    while(flag){
        // 방향 전환
        if(rotationTime[rotationIndex] == timer){
            checkWay(rotationIndex);
            rotationIndex++;
        }

        // 범위 확인
        if(isOut()){
            flag = false;
            timer++;
            break;
        }

        // 이동
        move();
        //debugPrint();
        timer++;
    }
    return timer;
}


int main(){
    cin >> boardSize >> appleCnt;
    for(int i = 0; i < appleCnt; i++){
        int y, x;
        cin >> y >> x;
        board[y][x] = 2; // 사과
    }
    cin >> rotationCnt;
    for(int i = 0; i < rotationCnt; i++){
        cin >> rotationTime[i] >> roationWay[i];
    }
    board[1][1] = 1; // start pos
    snake.push_front(make_pair(1,1));
    cout << Simulation();
    return 0;
}