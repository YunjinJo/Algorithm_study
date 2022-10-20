/*
1칸 이동 -> 1
2칸 이동 -> 1 + 1, 2
3칸 이동 -> 1 + 2, 2 + 1
4칸 이동 -> 2 + 2, 
n칸 이동 -> n - 2 + 2, n - 1 + 1 + T(n-3)

2칸 전까지 값 + 현재 값
또는
3칸 전까지 값 + 1칸 전 값 + 현재 값 -> 3개가 연속으로 올 수 없으므로
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 302;
int arr[MAX];
int DP[MAX];
int n;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    DP[0] = arr[0];
    DP[1] = max(arr[0] + arr[1], arr[1]);
    DP[2] = max(arr[0] + arr[2], arr[1] + arr[2]);
    for(int i = 3; i < n; i++){
        DP[i] = max(DP[i-2] + arr[i], arr[i-1] + arr[i] + DP[i-3]);
    }
    cout << DP[n-1];

    return 0;
}