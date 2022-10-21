/*

*/

#include <iostream>
#include <cstdio>
#include <limits.h>
#include <algorithm>
using namespace std;
const int MAX = 500001;
int n;
int DP[MAX];
int main(){
    cin >> n;
    DP[1] = 1;
    for(int i = 2; i <= n; i++){
        int minValue = INT_MAX;
        for(int j = 1; j * j <= i; j++){
            int temp = i - j * j;
            minValue = min(minValue, DP[temp]);
        }
        DP[i] = minValue + 1;
    }
    cout << DP[n];
    return 0;
}