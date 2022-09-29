#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(){
    string s;
    int n;
    int cnt = 0;
    int answer = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s;
        for(int j = 0; j < s.size(); j++){
            if(s[j] == 'O'){
                cnt++;
                answer += cnt;
            }
            else{
                cnt = 0;
            }
        }
        cout << answer << '\n';
        answer = 0;
        cnt = 0;
    }
    
    return 0;
}