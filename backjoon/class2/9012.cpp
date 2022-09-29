#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool result(string s){
    stack <char> paren;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == ')'){
            if(paren.empty()) return false;
            paren.pop();
        }
        else{
            paren.push(s[i]);
        }
    }
    if(paren.empty()) return true;
    else return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        if(result(s)) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }

    return 0;
}