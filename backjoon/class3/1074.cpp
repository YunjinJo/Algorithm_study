/*
n = 3
2 ^ 2 x 2^ 2로 4개 나눔 -> 한 칸에 16개
다시 4개로 나눔
다시 4개로 나눔
답 구함

*/

#include <iostream>
#include <cstdio>
using namespace std;

int n, r, c;
int answer;

void Z(int y, int x, int size){
    // 찾는 좌표에 도달
    if(y == r && x == c){
        cout << answer << '\n';
        return;
    }
    // 범위 안에 있으면
    if(r < y + size && r >= y && c < x + size && c >= x){
        Z(y, x, size / 2);
        Z(y, x + size / 2, size / 2);
        Z(y + size /2, x, size / 2);
        Z(y + size / 2, x + size / 2, size / 2);
    }
    // 범위 나감 (해당 좌표가 사분면에 없음)
    else{
        answer += size * size;
    }
}


int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n >> r >> c;
    Z(0, 0, (1 << n)); // 시작점 y, 시작점 x, size (1, 2, 4, 8, 16 ...)
    return 0;
}