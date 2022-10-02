#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>
#include <string>
using namespace std;

void result(string s){
    int size = s.size();
    stack <char> paren;
    for(int i = 0; i < size; i++){
        char currentChar = s[i];
        if(currentChar == '(' || currentChar == '['){
            paren.push(currentChar);
        }
        else if(currentChar == ')'){
            if(paren.empty()){
                cout << "no" << '\n';
                return;
            }
            char top = paren.top();
            if(top == '['){
                cout << "no" << '\n';
                return;
            }
            else if(top == '('){
                paren.pop();
            }
        }
        else if(currentChar == ']'){
            if(paren.empty()){
                cout << "no" << '\n';
                return;
            }
            char top = paren.top();
            if(top == '('){
                cout << "no" << '\n';
                return;
            }
            if(top == '['){
                paren.pop();
            }
        }
    }
    if(paren.empty()){
        cout << "yes" << '\n';
    }
    else{
        cout << "no" << '\n';
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    bool flag = true;
    while(flag){
        string s;
        getline(cin, s);
        if(s.size() == 1 && s[0] == '.'){
            flag = false;
            break;
        }
        result(s);

    }
    return 0;
}