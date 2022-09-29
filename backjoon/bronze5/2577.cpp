#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    long long int result = 0;
    int a, b, c;
    int count[10] = {0, };
    cin >> a >> b >> c;
    result = a * b * c;
    
    while(result != 0){
        count[result % 10]++;
        result /= 10;
    }
    
    for(int i = 0; i < 10; i++){
        cout << count[i] << '\n';
    }
    
    return 0;
}