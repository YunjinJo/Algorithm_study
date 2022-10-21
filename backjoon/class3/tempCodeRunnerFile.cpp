/*
1 = 1
2 = 1 1
3 = 1 1 1
4 = 2, 1 1 1 1
5 = 2 1
6 = 2 1 1
7 = 2 1 1 1
8 = 2 2
9 = 3, 2 2 1
10 = 3 1, 2 2 1 1
11 = 3 1 1
12 = 3 1 1 1, 2 2 2
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
    DP[2] = 1;
    DP[3] = 1;
    DP[4] = 2;
    for(int i = 5; i < n; i++){
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