#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int a, b;
    int temp = 0;
    cin >> a >> b;
    for(int i = 0; i < 3; i++){
        temp = (temp*10) + (a % 10); 
        a /= 10;
    }
    a = temp;
    temp = 0;
    for(int i = 0; i < 3; i++){
        temp = (temp*10) + (b % 10); 
        b /= 10;
    }
    b = temp;
    cout << max(a, b);
    
    return 0;
}