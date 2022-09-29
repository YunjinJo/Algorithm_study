#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int cnt = 0;
    int current;
    int result = 0;
    int resultCnt = 1;
    cin >> current;
    result = current;
    cnt++;
    while(cnt < 10){
        cin >> current;
        cnt++;
        if(result < current){
            result = current;
            resultCnt = cnt;
        }
    }
    cout << result << '\n';
    cout << resultCnt;
    return 0;
}