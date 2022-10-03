#include <iostream>
#include <cstdio>
#include <memory.h>
#include <cmath>
#include <algorithm>
using namespace std;
const int MAX = 500001;
const int COUNTMAX = 8001;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    int arr[MAX];
    int count[COUNTMAX];
    memset(arr, 0, sizeof(arr));
    memset(count, 0, sizeof(count));

    cin >> n;
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        arr[i] = temp;
        count[temp+4000]++;
    }
    sort(arr, arr+n);

    // 1. 산술평균 : N개의 수들의 합을 N으로 나눈 값
    double total = 0;
    for(int i = 0; i < n; i++){
        total += arr[i];
    }
    double answer = 0.0;
    answer = floor(total / n + 0.5); // 반올림

    cout.precision(1);
    cout << (int)answer << '\n';

    // 2. 중앙값 : N개의 수를 순서대로 나열했을 때 중앙에 위치하는 값

    cout << arr[n/2] << '\n';

    // 3. 최빈값 : N개의 수들 중 가장 많이 나타나는 값
    int cnt = 0;
    int maxValue = 0;
    int maxIndex = 0;
    for(int i = 0; i < COUNTMAX; i++){
        if(count[i] == 0) continue;
        else{
            if(maxValue < count[i]){
                maxValue = count[i];
                maxIndex = i;
                cnt = 1;
            }
            else if(maxValue == count[i]){
                cnt++;
                if(cnt == 2){
                    maxValue = count[i];
                    maxIndex = i;
                }
            }
        }
    }
    cout << maxIndex - 4000 << '\n';


    // 4. 범위 : N개의 수들 중 최댓값과 최솟값의 차이
    cout << arr[n-1] - arr[0];

    return 0;
}