/*
5
1 (1 1 1 1) -> DP[4]
1 (1 1 2)
1 (1 2 1)
1 (2 1 1)
1 (2 2)
1 (1 3)
1 (3 1)

2 (1 1 1) -> DP[3]
2 (1 2)
2 (2 1)
2 (3)

3 (1 1) -> DP[2]
3 (2)


13개

DP[4] = DP[3] + DP[2] + DP[1]
DP[5] = DP[4] + DP[3] + DP[2]

*/
#include <iostream>
#include <cstdio>
using namespace std;
const int MAX = 14;
int testcase;
int DP[MAX];

void calculateDP(){
    DP[0] = 0;
    DP[1] = 1;
    DP[2] = 2;
    DP[3] = 4;
    DP[4] = 7;
    for(int i = 5; i < MAX; i++){
        DP[i] = DP[i-1] + DP[i-2] + DP[i-3];
    }
}

int main(){
    cin >> testcase;
    calculateDP();
    for(int t = 0; t < testcase; t++){
        int n;
        cin >> n;
        cout << DP[n] << '\n';
    }
    return 0;
}