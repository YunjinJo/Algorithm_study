#include <iostream>
using namespace std;

int factorial(int x){
    if(x == 1 || x == 0){
        return 1;
    }
    else{
        return factorial(x - 1) * x;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    cout << factorial(n) / (factorial(n-k) * factorial(k));
    
    return 0;
}