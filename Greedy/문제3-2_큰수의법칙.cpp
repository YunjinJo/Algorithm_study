#include <stdio.h>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n,m,k;
vector<int> v; // int 타입을 저장하는 컨테이너 생성
int main()
{
    // 공백 기준으로 n, m, k가 입력된다.
    // n 배열의 크기
    // m 덧셈의 총 횟수
    // k 연속해서 더할 수 있는 횟수
    cout << "n, m, k를 입력해주세요.";
    cin >> n >> m >> k;

    // 배열을 공백을 기준으로 나누어 입력받는다.
    cout << "배열을 입력해주세요.";
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }

    sort(v.begin(), v.end()); // 입력받은 수 정렬
    int first = v[n-1]; // 가장 큰 수
    int second = v[n-2]; // 두번째로 큰 수

    int array_max = k+1; // 더해지는 연속된 배열, ex) {6+6+6+5} 가장 큰 값이 k번 더해지고, 두번째로 큰 값이 한 번 더해진다.

    int cnt = (m / (k+1)); // 연속된 배열을 몇 번 나오는지 계산 ex) 8 / 4 = 2 -> 2번 나온다.
    cnt = cnt * k; // 가장 큰 값이 더해지는 횟수 ex) 2 * 3 = 6 -> 6이 6번 더해진다.
    
    int cnt_rest = m % (k+1); // 나누어 떨어지지 않는 경우 나머지를 구한다.
    cnt = cnt + cnt_rest; // cnt에 더한다

    int result = 0;
    result += cnt * first; // 가장 큰 수가 cnt번 더해진다.
    result += (m - cnt) * second; // 남은 횟수만큼 두번째로 큰 수가 더해진다.

    cout << result << '\n'; // 결과 출력    
}