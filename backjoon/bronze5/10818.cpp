#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    int resultMax = -1000001;
    int resultMin = 1000001;
    cin >> n;
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        resultMax = max(resultMax, temp);
        resultMin = min(resultMin, temp);
    }
    cout << resultMin << ' ' << resultMax;
    return 0;
}