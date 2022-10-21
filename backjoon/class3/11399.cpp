#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

vector <int> timer;
int n;
int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        timer.push_back(temp);
    }
    sort(timer.begin(), timer.end());
    int answer = 0;
    for(int i = 0; i < n; i++){
        int temp = 0;
        temp = timer[i] * (n - i);
        answer += temp;
    }
    cout << answer;
    return 0;
}