#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

string s;
string cmp;
int n, m;

bool compareString(int index){
    int cmpSize = cmp.size();
    if(m - index < cmpSize) return false;
    for(int i = 0; i < cmpSize; i++){
        if(s[index + i] != cmp[i]) return false;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int answer = 0;

    // 값 입력
    cin >> n >> m;
    cin.ignore();
    getline(cin, s);

    // 비교할 문자열 만들기
    for(int i = 0; i < n; i++){
        cmp += "IO";
    }
    cmp += "I";
    
    for(int i = 0; i < m; i++){
        if(compareString(i)) answer++;
    }
    cout << answer;
}