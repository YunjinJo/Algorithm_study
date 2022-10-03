// 모듈러 연산
// 1. (a + b) mod n = {(a mod n) + (b mod n)} mod n
// 2. (a - b) mod n = {(a mod n) - (b mod n)} mod n
// 3. (a * b) mod n = {(a mod n) * (b mod n)} mod n

#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

long long int R = 1;
long long int MOD = 1234567891;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    unsigned long long int hash = 0;
    string s;
    cin >> n;
    cin >> s;
    for(int i = 0; i < n; i++){
        // 알파벳을 숫자로 변환
        char alpha = s[i];
        alpha -= 'a';
        alpha += 1;
        // 해시 계산
        hash += alpha * R;
        hash %= MOD;
        R *= 31;
        R %= MOD;
    }
    cout << hash;
    return 0;
}