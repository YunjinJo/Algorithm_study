#include <iostream>
#include <memory.h>
using namespace std;

const int MAX = 15;
int apt[MAX][MAX];

void cal(){
    memset(apt, 0, sizeof(apt));

    // 0층 채우기
    for(int i = 1; i < MAX; i++){
        apt[0][i] = i;
    }

    // 1층 ~ 채우기
    for(int i = 1; i < MAX; i++){ // 층
        for(int j = 1; j < MAX; j++){ // 호
            for(int p = 1; p <= j; p++){ // 사람 구하기
                apt[i][j] += apt[i - 1][p];
            }
        }
    }
}


int main(){
    int t, k, n;
    cin >> t;
    cal();
    
    for(int i = 0 ; i < t; i++){
        cin >> k >> n;
        cout << apt[k][n] << '\n';
    }
    return 0;
}