#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int getResult(int x){
    int answer = 0;
    // 2와 5의 개수를 센다 -> 10을 만들 수 있으므로
    int twoCount = 0;
    int fiveCount = 0;
    for(int i = 2; i <= x; i++){
        int temp = i;
        if(i % 2 == 0){
            while(temp != 0){
                temp /= 2;
                twoCount++;
                if(temp % 2 != 0) break;
            }
        }

        temp = i;
        if(i % 5 == 0){
            while(temp != 0){
                temp /= 5;
                fiveCount++;
                if(temp % 5 != 0) break;
            }
        }
    }
    return min(twoCount, fiveCount);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    
    cout << getResult(n);
    return 0;
}