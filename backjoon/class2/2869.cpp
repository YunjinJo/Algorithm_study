// 시간 제한으로 인해 반복문 없이 풀기
// 1 0 + up < height
// 2 0 + (up - down) + up < height
// n 0 + (n - 1)(up - down) + up < height
// n >= (height - up) / (up - down) + 1
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b, v;
    cin >> a >> b >> v;

    int answer = 0;
    // 미리 1을 빼고 나중에 1 더함
    answer = (v - b - 1) / (a - b) + 1;
    cout << answer;
    return 0;
}