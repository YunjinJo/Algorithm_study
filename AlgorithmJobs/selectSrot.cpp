#include <stdio.h>
#include <iostream>
using namespace std;

/*
선택정렬
최솟값을 앞으로 계속 이동시킴
|7 8 5 4 -> 4 |7 8 5 -> 4 5 |7 8 -> 4 5 7 |8 -> 4 5 7 8|
*/
int main()
{
    int n;
    int data[100];
    cin >> n;
    //데이터 입력
    for(int i = 0; i < n; i++)
    {
        cin >> data[i];
    }

    for(int i = 0; i < n; i++)
    {
        // i번째에 최솟값을 넣는다
        // i번째부터 맨 끝가지의 값중 최솟값
        int index = i;
        for(int j = i; j < n; j++)
        {
            // 최솟값 판단
            if(data[index] > data[j])
            {
                index = j;
            }
        }
        int temp = data[i];
        data[i] = data[index];
        data[index] = temp;



    }


    // 출력
    for(int i = 0; i < n; i++)
    {
        cout << data[i] << " ";
    }
    return 0;
}