#include<bits/stdc++.h>
using namespace std;

int factorial(int number){
    if(number == 1 || number == 0)
        return 1;
    else
        return factorial(number - 1) * number;
}

int main(){
    int n;
    cin >> n;
    cout << factorial(n);
    return 0;
}