#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX = 20;
int n;
int t[MAX], p[MAX], d[MAX];

int cmp(){
    int result = 0;
    for(int i = 1; i <= n; i++){
        if(i + t[i] <= n+1){
            d[i+t[i]] = max(d[i + t[i]], d[i] + p[i]);
            result = max(result, d[i + t[i]]);
        }
        d[i + 1] = max(d[i + 1], d[i]);
        result = max(result, d[i+1]);
    }
    return result;
}

int main(){
    int answer = 0;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> t[i] >> p[i];
    }
    cout << cmp();
    return 0;
}