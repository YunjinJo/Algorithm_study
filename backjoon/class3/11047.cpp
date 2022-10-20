#include <iostream>
#include <cstdio>
using namespace std;
const int MAX = 11;

int n, k;
int coin[MAX];


int getResult(){
    int answer = 0;
    for(int i = n-1; i >= 0; i--){
        int temp = k / coin[i];
        if(temp != 0){
            answer += temp;
        }
        k = k - (coin[i] * temp);
    }
    return answer;
}

int main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> coin[i];
    }
    cout << getResult();
    return 0;
}