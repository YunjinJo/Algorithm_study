#include <iostream>
using namespace std;

int gcd(int x, int y){
    int r;
    while(y != 0){
        r = x % y;
        x = y;
        y = r;
    }
    return x;
}

int lcm(int x, int y){
    return x * y / gcd(x, y);
}

int main(){
    int n, m;
    cin >> n >> m;
    cout << gcd(n, m) << '\n' << lcm(n, m);
    return 0;
}