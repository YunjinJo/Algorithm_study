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

// 0 1
// 2 3

int dir[2][2] = {{1,2}, {3,4}};

int n, r, c;
int divideNum;
int answer = -1;

void recur(int x1, int y1, int x2, int y2){
    int midX = (x1 + x2) / 2;
    int midY = (y1 + y2) / 2;
    int x = 0;
    int y = 0;

    if(x1 == x2 || y1 == y2){
        return;
    }
    else{
        if(midX > c){
            x++;
        }
        if(midY > r){
            y++;
        }

        
    }
}



int main(){
    cin >> n >> r >> c;
    divideNum = n-1;




    return 0;
}