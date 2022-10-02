// 1 2 3 4
// 1 2  stack 4 3
// 1 2 5 6
// 1 2 5  stack 4 3 6
// 1 2 5 7 8
// stack 4 3 6 8 7 5 2 1

#include <iostream>
#include <stack>
#include <cstdio>
#include <memory.h>
#include <vector>
using namespace std;

const int MAX = 100001;

int n;
vector<char> answer;
stack <int> s1;
stack <int> s2;
int arr[MAX];

void result(){
    int cnt = 1;
    int index = 0;
    while(cnt <= n){
        if(s1.empty()){
            s1.push(cnt);
            cnt++;
            answer.push_back('+');
        }
        if(arr[index] == s1.top()){
            s2.push(s1.top());
            s1.pop();
            index++;
            answer.push_back('-');
        }
        else{
            s1.push(cnt);
            cnt++;
            answer.push_back('+');
        }
    }
    int repeat = s1.size();
    for(int i = 0; i < repeat; i++){
        s2.push(s1.top());
        s1.pop();
        answer.push_back('-');
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    memset(arr, 0, sizeof(arr));
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        arr[i] = temp;
    }
    result();
    for(int i = n - 1; i >= 0; i--){
        if(arr[i] == s2.top()){
            s2.pop();
        }
        else{
            cout << "NO";
            return 0;
        }
    }

    for(int i = 0; i < answer.size(); i++){
        cout << answer[i] << '\n';
    }
    return 0;
}