/*
1 -> 1
2 -> = || 2
3 -> =|, |=, |||,  3
4 -> == |||| |=| ||= =|| 5
5 -> ==| =|= |== ||||| |||= ||=| |=|| =||| 8
6 -> 13
7 -> 21
8 -> 34
9 -> 55

T(n) = T(n-1) + T(n-2)
*/

#include <iostream>
#include <cstdio>
using namespace std;
const int MAX = 1002;

int n;
int DP[MAX];

int main(){
    cin >> n;
    DP[1] = 1;
    DP[2] = 2;
    DP[3] = 3;
    for(int i = 4; i <= n;i++){
        DP[i] = (DP[i-1] + DP[i-2]) % 10007;
    }
    cout << DP[n];
    return 0;
}