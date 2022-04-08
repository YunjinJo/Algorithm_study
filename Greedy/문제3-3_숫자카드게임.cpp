// 숫자가 적힌 카드가 n x m의 크기로 놓여있다.
// 뽑고 싶은 카드의 행을 선택한다.
// 선택된 행의 카드들 중 가장 작은 수의 카드를 뽑아야 한다.
// 이를 고려하여 뽑을 수 있는 가장 큰 숫자가 무엇인지 출력해야 한다.
/*
ex
input
3 3
3 1 2
4 1 4
2 2 2

output
2

input
2 4
7 3 1 8
3 3 3 4

output
3
*/
#include<bits/stdc++.h>
int n, m, result;
std::vector<int> v;


int main()
{
    std::cout << "n과 m 값을 입력해주세요.";
    std::cin >> n >> m;

    //int arr[n] = {0, };
    result = 0;

    std::cout << "카드들의 숫자를 입력해주세요.";
    for(int i = 0; i < m; i++) // 모든 행을 탐색한다.
    {
        int num_min = 10001; // 최대로 나올 수 있는 값이 10000이므로 10001로 설정한다.
        for(int j = 0; j < n; j++) // 모든 열을 탐색한다.
        {
            int x;
            std::cin >> x;
            if(x < num_min) // num_min = min(num_min, x); 로 대체 가능
            {
                num_min = x;
            }
            
        }
        v.push_back(num_min);

        if(result < v[i]) // result = max(result, num_min); 으로 대체 가능
        {
            result = v[i];
        }
    }
    std::cout << "뽑을 수 있는 가장 큰 값은 " << result << "입니다.";
    

}
