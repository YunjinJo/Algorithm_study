/*
8 x 8 크기의 체스판 (1 ~ 8 x a ~ h)
나이트의 위치 입력
이 때 나이트가 이동할 수 있는 좌표의 경우의 수를 구하시오.

input
a1

output
2

input
c2

output
6
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    //시간 측정
    clock_t start, end;
    double result;

    //변수 설정
    int current_x = 0;
    int current_y = 0;
    char column[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'}; 
    /*

          *- -*
        *   |   *
        |   |   |
        - - # - -
        |   |   |
        *   |   *
          *- -*
        
    */

    int movement_x[] = {-1, 1, -1, 1, -2, -2, 2, 2}; // x축으로 이동할 수 있는 경우의 수
    int movement_y[] = {-2, -2, 2, 2, -1, 1, -1, 1}; // y축으로 이동할 수 있는 경우의 수
    int count = 0;
    

    string knight;
    cout << "나이트의 위치를 입력해주세요." << '\n';
    getline(cin, knight);

    start = clock(); // 측정 시작

    // 좌표 파싱
    for(int i = 0; i < 8; i++) // a, b, c...을 숫자 1, 2, 3...으로 변경
    {
        if(knight[0] == column[i])
        {
            current_x = i + 1;
        }
    }

    /*
    current_x = knight[0] - 'a' + 1;
    로 대체 가능
    */

    // ASCII 값에 따라 0 = 48, 1 = 49, ... , 9 = 57이므로
    // char형 숫자문자 - '0' = 숫자 가 나온다.
    current_y = knight[1] - '0'; 
    

    // 경우의 수 계산
    for(int j = 0; j < 8; j++)
    {
        int temp_x = 0;
        int temp_y = 0;
        // L자로 이동
        temp_x = current_x + movement_x[j];
        temp_y = current_y + movement_y[j];
        
        if((0 < temp_x) && (temp_x < 9) && (0 < temp_y) && (temp_y < 9)) // 체스판을 벗어났는지 체크
        {
            count++;
        }
        
    }

    end = clock(); // 측정 종료
    result = (double)(end - start);
    cout << result << "ms" << '\n';

    // cout << "x좌표" << current_x << '\n';
    // cout << "y좌표" << current_y << '\n';
    cout << count;

    return 0;
}