#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

int testcase;
int n;
int m; // 찾으려는 수 인덱스 0 ~ n-1
int findNumber; // 찾으려는 수

int result(queue <pair<int, int>> q, int x){
    int answer = 0;
    int frontIndex;
    int frontValue;
    if(n == 1) return 1;

    while(1){
        int maxValue = -1;
        int maxIndex = 0;
        for(int i = 0; i < q.size(); i++){
            frontIndex = q.front().first;
            frontValue = q.front().second;
            if(maxValue < frontValue){
                maxIndex = frontIndex;
                maxValue = frontValue;
            }
            q.pop();
            q.push(make_pair(frontIndex, frontValue));
        }
        //cout << maxValue << ' ' << maxIndex << '\n';

        if(maxValue == findNumber && maxIndex == m){
            return answer + 1;
        }
        else{
            // 최대값 빼기
            while(1){
                frontIndex = q.front().first;
                frontValue = q.front().second;
                if(maxIndex == frontIndex && maxValue == frontValue){
                    q.pop();
                    answer++;
                    break;
                }
                else{
                    q.pop();
                    q.push(make_pair(frontIndex, frontValue));
                }
            }
        }
    }
    return answer;
}


int main(){
    ios:: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> testcase;
    for(int i = 0; i < testcase; i++){
        int cnt = 0;
        queue <pair<int, int>> printer; // 인덱스, 값
        cin >> n >> m;
        for(int j = 0; j < n; j++){
            int temp;
            cin >> temp;
            printer.push(make_pair(j,temp));
            if(j == m) findNumber = temp;
            
        }
        cout << result(printer, findNumber) << '\n';
    }

    return 0;
}