#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> v1;

bool inVector(int findNumber){
    int start = 0;
    int end = v1.size() - 1;

    if(v1[start] > findNumber || v1[end] < findNumber) return false;
    else if(v1[start] == findNumber || v1[end] == findNumber) return true;

    while(start + 1 < end){
        int mid = (start + end) / 2;
        if(v1[mid] == findNumber) return true;
        else if(v1[mid] > findNumber) end = mid;
        else start = mid;
    }
    return false;
}

int main(){
    int n, m;
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        v1.push_back(temp);
    }
    cin >> m;
    sort(v1.begin(), v1.end());
    for(int i = 0; i < m; i++){
        int temp;
        cin >> temp;
        cout << inVector(temp) << '\n';
    }
    return 0;
}