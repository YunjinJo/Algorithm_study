#include <iostream>
#include <memory.h>
#include <cstdio>
using namespace std;

const int MAX = 1000001;
bool prime[MAX];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(prime, true, sizeof(prime));
    prime[0] = false;
    prime[1] = false;
    for(int i = 2; i < MAX; i++){
        for(int j = i*2; j < MAX; j+=i){
            prime[j] = false;
        }
    }

    int n, m;
    cin >> n >> m;
    for(int i = n; i <= m; i++){
        if(prime[i]) cout << i << '\n';
    }
    

    return 0;
}