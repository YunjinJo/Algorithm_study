#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

long long int mul(int x){
    long long int temp = 1;
    for(int i = 0; i < x; i++){
        temp *= 31;
    }
    return temp;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    long long int hash = 0;
    string s;
    cin >> n;
    cin >> s;
    for(int i = 0; i < n; i++){
        char alpha = s[i];
        alpha -= 'a';
        alpha += 1;
        hash += (long long int)alpha * mul(i);
    }
    cout << hash;
    return 0;
}