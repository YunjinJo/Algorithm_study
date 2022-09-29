#include <iostream>
#include <vector>
using namespace std;

int n, k;
long long int maxValue = 0;
long long int input[10001];
long long int low, mid, high;

int main(){
    long long int answer;
    cin >> k >> n;
    for(int i = 0; i < k; i++){
        cin >> input[i];
        if(maxValue < input[i]) maxValue = input[i];
    }

    low = 1; // low Index
    high = maxValue; // high Index
    answer = 0;

    // 이진탐색
    while(low <= high){
        mid = (low + high) / 2;
        int cnt = 0;
        for(int i = 0; i < k; i++){
            cnt += input[i] / mid;
        }

        if(cnt >= n){ // 필요한 개수 이상
            low = mid + 1;
            if(answer < mid)
                answer = mid;
        }
        else{
            high = mid - 1;
        }
    }
    cout << answer;
    return 0;
}