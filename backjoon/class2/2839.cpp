#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    int answer = 0;
    cin >> n;

    while(n >= 0){
        // 5로 나누어 떨어짐 -> 최소
        if(n % 5 == 0){
            answer += (n / 5);
            cout << answer;
            return 0;
        }
        // 아니면 3을 뺌
        n -= 3;
        answer++;
    }
    // 불가능
    cout << -1;
    
    return 0;
}