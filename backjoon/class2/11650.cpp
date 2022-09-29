#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int, int> p1, pair<int, int> p2){
    if(p1.first < p2.first){
        return true;
    }
    else if(p1.first > p2.first){
        return false;
    }
    else{
        if(p1.second < p2.second){
            return true;
        }
        else{
            return false;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    vector<pair<int, int>> point;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        point.push_back(make_pair(x, y));
    }
    sort(point.begin(), point.end(), cmp);
    for(int i = 0; i < n; i++){
        cout << point[i].first << ' ';
        cout << point[i].second << '\n';
    }
    return 0;
}