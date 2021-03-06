/*
정수 N 입력
00시00분00초 ~ N시 59분 59초 중에서 하나라도 3이 포함되는 모든 경우의 수 구하기
ex) 00시 13분 30초

input
5

output
11475
*/

/*
0 ~ 59초 -> 3, 13, 23, 3x전부, 43, 53 -> 15개
0 ~ 59분 -> 3, 13, 23, 3x전부, 43, 53 -> 각 분마다 15개, 3이 들어가는건 60개
0 ~ 12시 -> 3시 전부 -> 6400개


*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    //시간 측정
    clock_t start, end;
    double result;
    
    // 변수 선언
    int N = 0; // 시간
    int count = 0; // 개수 카운트

    cout << "시간 N을 입력해주세요.: " << '\n';
    cin >> N;
    cin.ignore();
    start = clock(); // 측정 시작

    for(int minute = 0; minute < 60; minute++) // 0 ~ 59분 사이 카운팅
    {
        string input_num_min = to_string(minute); // int를 string으로 변환

        for(int second = 0; second < 60; second++) // 0 ~ 59초 사이 카운팅
        {
            string input_num_sec = to_string(second);
            if(input_num_min[0] == '3' || input_num_min[1] == '3') // 분단위가 3, 13, 23...인 경우
            {
                count ++;
            }
            else if(input_num_sec[0] == '3' || input_num_sec[1] == '3') // 초단위가 3, 13, 23...인 경우
            {
                count++;
            }

        }
    }

    if(N > 2)
    {
        count = count * N;
        count = count + 3600; // 3시는 모두 해당하므로 3600개
    }

    else
    {
        count = count * (N+1);
    }



    end = clock(); // 측정 종료
    result = (double)(end - start);
    cout << result << "ms" << '\n';

    cout << count;
    return 0;

}