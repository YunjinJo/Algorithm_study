#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 100000001;
int n, t;
bool visited[MAX];



int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    for(int testcase = 0; testcase < t; testcase++){
        priority_queue<pair<int, int>> maxHeap; // 입력 숫자, 인덱스
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > minHeap;
        cin >> n;
        for(int i = 0; i < n; i++){
            char op;
            int num;
            cin >> op >> num;

            if(op == 'I'){
                // 똑같이 집어넣음
                maxHeap.push({num,i});
                minHeap.push({num,i});
                visited[i] = true;
            }
            else{
                // 최댓값 삭제
                if(num == 1){
                    // 최댓값 삭제
                    while(!maxHeap.empty() && !visited[maxHeap.top().second]){
                        maxHeap.pop();
                    }
                    // 똑같이 맞춤
                    if(!maxHeap.empty()){
                        visited[maxHeap.top().second] = false;
                        maxHeap.pop();
                    }
                }
                // 최솟값 삭제
                else{
                    // 최솟값 삭제
                    while(!minHeap.empty() && !visited[minHeap.top().second]){
                        minHeap.pop();
                    }
                    // 똑같이 맞춤
                    if(!minHeap.empty()){
                        visited[minHeap.top().second] = false;
                        minHeap.pop();
                    }
                }
            }


        }

        while(!maxHeap.empty() && !visited[maxHeap.top().second]){
            maxHeap.pop();
        }
        while(!minHeap.empty() && !visited[minHeap.top().second]){
            minHeap.pop();
        }
        if(minHeap.empty() && maxHeap.empty()){
            cout << "EMPTY\n";
        }
        else{
            cout << maxHeap.top().first << ' ' << minHeap.top().first << '\n';
        }
    }
    return 0;
}