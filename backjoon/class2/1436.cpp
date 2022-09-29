// 666 1666 2666 3666 4666 5666 6660 6661 6662 ...
// 666이 들어가는 숫자를 크기 순으로 나열

#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int cnt = 0;
    int currentNumber = 0;
    int temp;
    while(cnt != n){
        currentNumber++;
        temp = currentNumber;
        while(temp != 0){
            if(temp % 1000 == 666){
                cnt++;
                break;
            }
            else{
                temp /= 10;
            }
        }
    }
    cout << currentNumber;
    return 0;
}