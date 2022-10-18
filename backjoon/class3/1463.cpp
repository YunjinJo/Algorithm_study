// 2 -> 1
// 3 -> 1
// 4 -> 2 -> T(4) = T(3) + 1;
// 5 -> 3 -> T(5) = T(4) + 1;
// 6 -> 2 -> T(6) = T(5) + 1, T(3) + 1;
// 7 -> 3
// 8 -> 3

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX = 1000001;
int arr[MAX];

int main(){
    int X; // 2 ~ 10^6
    int cnt = 0;
    cin >> X;



    for(int i = 2; i <= X; i++){
        // 1을 뺌
        arr[i] = arr[i - 1] + 1;
        if(i % 2 == 0){ // 2로 나누어 떨어지면
            // 1을 뺀 것과 i / 2를 한 횟수중 작은것 기록
            arr[i] = min(arr[i], arr[i / 2] + 1);
        }
        if(i % 3 == 0){ // 3으로 나누어 떨어지면
            arr[i] = min(arr[i], arr[i / 3] + 1);
        }
    }
    cout << arr[X];

    return 0;
}