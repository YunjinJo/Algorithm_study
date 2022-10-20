#include <iostream>
#include <cstdio>
using namespace std;
const int MAX = 101;
int n;
int arr[MAX][MAX] = {0, };

void floyd(){
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(arr[i][k] && arr[k][j]) arr[i][j] = 1;
            }
        }
    }
}

int main(){
    int temp;
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }
    floyd();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}