#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    int temp;
    int result = 0;
    for(int i = 0; i < n; i++){
        scanf("%1d", &temp);
        result += temp;
    }
    cout << result;
    return 0;
}