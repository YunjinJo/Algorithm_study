#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 100001;
int n;
vector <pair<int, int>> v; // 종료 시점, 시작 시점

int main() {
    cin >> n;
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        v.push_back(make_pair(y, x));
    }
    sort(v.begin(), v.end());
    int cnt = 1;
    int cur = v[0].first; // 가장 빠른 종료 시점
    for(int i = 1; i < n; i++){
        if(cur <= v[i].second){ // v[i]의 시작 시점과 비교
            cur = v[i].first;
            cnt++;
        }
    }
    cout << cnt;

    return 0;
}
