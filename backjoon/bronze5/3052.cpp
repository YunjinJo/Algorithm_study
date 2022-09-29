#include <iostream>
using namespace std;

const int MAX = 42;

int main(){
    bool check[MAX] = {0, };
    int cnt = 0;
    for(int i = 0; i < 10; i++){
        int temp;
        cin >> temp;
        check[temp % 42] = true;
    }

    for(int i = 0; i < MAX; i++){
        if(check[i]) cnt++;
    }
    cout << cnt;
    
    return 0;
}