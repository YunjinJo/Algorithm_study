#include <iostream>
#include <vector>
using namespace std;


int main(){
    int n;
    int answer;
    int minValue;

    cin >> n;
    minValue = 1000001;
    answer = n;

    while(answer >= 1){
        int temp;
        int sum;
        temp = answer;
        sum = answer;
        while(temp != 0){
            int add;
            add = temp % 10;
            sum += add;
            temp /= 10;
        }

        if(sum == n){
            if(minValue > answer){
                minValue = answer;
            }
        }
        answer--;
    }
    if(minValue == 1000001)
        cout << "0";
    else
        cout << minValue;
    return 0;
}