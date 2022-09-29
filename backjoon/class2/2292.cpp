// 1
// 2 3 4 5 6 7
// 1개, 1+6개, 1+6+12개, 1+6+12+18 ...
// f(n) = f(n-1) + 6 x n - 1
#include <iostream>
using namespace std;


int main(){
    long long int n;
    bool flag = true;
    long long int X = 1;
    long long int cnt = 0;
    cin >> n;

    while(flag){
        X = X + 6*cnt;
        if(X > n){
            flag = false;
            break;
        }
        else{
            cnt++;
        }
    }
    cout << cnt + 1;
    return 0;
}