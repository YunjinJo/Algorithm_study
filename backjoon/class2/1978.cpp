#include <iostream>
#include <algorithm>
#include <vector>
#include <memory.h>
using namespace std;

const int MAX = 1001;
bool prime[MAX];

void findPrime(){
    for(int i = 2; i < MAX; i++){
        for(int j = i*2; j < MAX; j+=i){
            prime[j] = false;
        }
    }
    prime[0] = false;
    prime[1] = false;
}

int main() {
    memset(prime, true, sizeof(prime));
    findPrime();
    int n;
    int cnt = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        if(prime[temp] == true){
            cnt++;
        }
    }
    cout << cnt;
  return 0;
}