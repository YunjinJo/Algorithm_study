#include <iostream>
#include <algorithm>
#include <memory.h>
using namespace std;
const int MAX = 10001;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int arr[MAX];
    memset(arr, 0, sizeof(arr));
    int maxValue = 0;
    int n;
    cin>> n;
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        arr[temp]++;
        maxValue = max(maxValue, temp);
    }

    for(int i = 1; i <= maxValue; i++){
        if(arr[i]){
            for(int j = 0; j < arr[i]; j++){
                cout << i << '\n';
            }
        }        
    }
    return 0;
}