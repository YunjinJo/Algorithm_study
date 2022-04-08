/*
어떠한 수 N을 입력받는다. (2 <= N <= 100,000)
나누는 수 K를 입력받는다. (2 <= K <= 100,000)

아래의 2가지 과정만을 반복하여 N의 값을 1로 만든다.
1. N에서 1을 뺀다.
2. N을 K로 나눈다. (단 N이 K로 반드시 나누어 떨어진다.)
N이 1이 되게 하는 최소 시행 횟수를 출력한다.

ex
input
25 5

output
2


#include <bits/stdc++.h>

int fun_1(int num) // 1번 동작
{
    return num - 1;
}

int fun_2(int num, int k) // 2번 동작
{
    return num/k;
}

int n, k, count;

int main()
{
    std::cout << "n과 k의 값을 입력해주세요.";
    std::cin >> n >> k;
    count = 0;

    while(n != 1) // n == 1이 될 때 까지 무한 반복한다.
    {
        if(n % k == 0) // 나누는 것이 무조건 좋으므로 먼저 확인한다.
        {
            n = fun_2(n, k);
            count++;
        }

        else // 나눌 수 없다면 뺀다.
        {
            n = fun_1(n);
            count++;
        }
        
    }

    std::cout << "답은 " << count << "입니다.";

}
*/

#include <bits/stdc++.h>

using namespace std;

int n, k;
int result;

int main() {
    // N, K를 공백을 기준으로 구분하여 입력 받기
    cin >> n >> k;

    while (true) {
        // N이 K로 나누어 떨어지는 수가 될 때까지만 1씩 빼기
        int target = (n / k) * k; // k로 나누어 떨어지는 수를 계산한다. ex) (20 / 3) * 3 = 18
        result += (n - target); // 1로 뺀 만큼 연산 횟수를 추가한다. ex) result = (20 - 18) + result = 2 + result
        n = target; // n의 값을 변경한다. ex) n = 18

        // N이 K보다 작을 때 (더 이상 나눌 수 없을 때) 반복문 탈출
        if (n < k) break; // n = 2 일 때 탈출
        // K로 나누기
        result += 1; // 연산 횟수 1을 추가한다.
        n /= k; // n = n / k ex) 18/3 -> 6 -> 2
    }

    // 마지막으로 남은 수에 대하여 1씩 빼기
    result += (n - 1); // 만약 n = 1이 아닌 경우, 1을 계속 뺀다.
    cout << result << '\n';
}