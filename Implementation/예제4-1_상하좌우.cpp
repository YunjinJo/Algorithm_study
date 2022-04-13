/*
N x N 크기 정사각형 공간 (1 <= N <= 100)
(1,1) 왼쪽 위에서 시작
L 왼쪽으로 한 칸 이동
R 오른쪽 
U 위쪽
D 아래쪽
(1 <= 이동 횟수 <= 100)

지도의 크기와 이동 계획서가 주어졌을 때 도착 지점의 좌표 표시
input
5
R R R U D D

output
3 4
*/

#include <bits/stdc++.h>
using namespace std;

// Global Var
int N = 0;        // 공간의 크기
string movements; // 이동 명령어
int current_x = 1; // 현재 x좌표
int current_y = 1; // 현재 y좌표
char moveTypes[4] = {'L', 'R', 'U', 'D'}; // 가능한 이동 명령어 집합
int dx[4] = {0, 0, -1, 1}; // 각 이동 명령어의 x좌표 움직임
int dy[4] = {-1, 1, 0, 0}; // 각 이동 명령어의 y좌표 움직임


int main()
{
    cout << "N의 값을 입력해주세요." << "\n";
    cin >> N;

    cout << "이동 계획서를 입력해주세요." << "\n";
    cin.ignore(); // N을 입력받을 때 남은 버퍼 비움, cin은 엔터를 버리지 않고 버퍼에 남긴다
    getline(cin, movements); // (입력 스트림 오브젝트, 문자열을 저장할 string 객체)
    

    for(int i = 0; i < movements.size(); i++) // movements 입력받은 만큼 반복
    {
        char move = movements[i]; // i번째 이동 명령
        int temp_x = 0; // x축으로 이동할 총 횟수
        int temp_y = 0; // y축으로 이동할 총 횟수
        for (int j = 0; j < 4; j++)
        {
            if(move == moveTypes[j]) // 이동 명령에 따라 임시로 이동
            {
                temp_x = current_x + dx[j];
                temp_y = current_y + dy[j];
            }

            if(temp_x < 1 || temp_y < 1 || temp_x > N || temp_y > N) // 범위를 벗어난다면 넘긴다
                continue;

            current_x = temp_x; // 현재 x좌표로 저장
            current_y = temp_y; // 현재 y좌표로 저장
        }
    }

    cout << current_x << ' ' << current_y << '\n';
    return 0;
}