// 0
// 1
// 2 -> 1 1
// 3 -> 1 2
// 4 -> T(3) + T(2) -> 2 3
// 5 -> T(4) + T(3) -> 3 5
// 6 -> T(5) + T(4) -> 5 8
// T(n) = T(n - 1) + T(n - 2) 
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int maxValue = 0;
vector<int> v;
vector<pair<int, int>> DP; // 0의 개수, 1의 개수

void getResult(int x){
    DP.push_back(make_pair(1, 0));
    DP.push_back(make_pair(0, 1));
    for(int i = 2; i <= x; i++){
        int n1 = DP[i-1].first;
        int n2 = DP[i-1].second;
        int m1 = DP[i-2].first;
        int m2 = DP[i-2].second;
        DP.push_back(make_pair(n1+m1, n2+m2));
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++){
        int input;
        cin >> input;
        v.push_back(input);
        maxValue = max(maxValue, input);
    }
    getResult(maxValue);
    for(int i = 0; i < n; i++){
        cout << DP[v[i]].first << ' ' << DP[v[i]].second << '\n';
    }

    return 0;
}