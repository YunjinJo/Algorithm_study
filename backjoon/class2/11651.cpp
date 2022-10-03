#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

vector <pair<int, int>> point;

bool cmp(pair<int, int> p1, pair<int, int> p2){
    int x1 = p1.first;
    int y1 = p1.second;
    int x2 = p2.first;
    int y2 = p2.second;
    if(y1 < y2){
        return true;
    }
    else if(y1 == y2){
        if(x1 < x2){
            return true;
        }
    }
    else{
        return false;
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        int y;
        cin >> x >> y;
        point.push_back(make_pair(x, y));
    }
    sort(point.begin(), point.end(), cmp);

    for(int i = 0; i < n; i++){
        cout << point[i].first << ' ' << point[i].second << '\n';
    }
    return 0;
}