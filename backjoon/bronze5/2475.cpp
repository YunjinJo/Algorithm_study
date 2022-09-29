#include <iostream>
using namespace std;

int main(){
    int arr[6];
    int total = 0;
    for(int i = 0; i < 5; i++){
        int temp;
        cin >> temp;
        total = total + temp * temp;
        arr[i] = temp;
    }
    arr[5] = total % 10;
    cout << arr[5];
    return 0;
}