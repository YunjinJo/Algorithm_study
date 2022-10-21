#include <iostream>
#include <cstdio>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int n, m;
map <string, string> pass; // 즉시 value에 도달 가능

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        string s1, s2;
        cin >> s1 >> s2;
        pass[s1] = s2;
    }
    
    
    for(int i = 0; i < m; i++){
        string s;
        cin >> s;
        cout << pass[s] << '\n';
    }
    return 0;
}