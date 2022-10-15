#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;


const int comb_MAX = 4;
const int cnt_MAX = 12;
int n;
int numbers[cnt_MAX];
int comb_select[cnt_MAX];
int comb[comb_MAX]; // + - * / 0 1 2 3


int minValue = 1000000001;
int maxValue = -1000000001;

void DFS(int cnt, int total){
    if(cnt == n){
        maxValue = max(maxValue, total);
        minValue = min(minValue, total);
        return;
    }
    for(int i = 0; i < 4; i++){
        if(comb[i] > 0){
            comb[i]--;
            if(i == 0) DFS(cnt + 1, total + numbers[cnt]);
            else if(i == 1) DFS(cnt + 1, total - numbers[cnt]);
            else if(i == 2) DFS(cnt + 1, total * numbers[cnt]);
            else if(i == 3) DFS(cnt + 1, total / numbers[cnt]);
            comb[i]++;
        }
    }
    return;

}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> numbers[i];
    }
    for(int i = 0; i < comb_MAX; i++){
        cin >> comb[i];
    }
    DFS(1, numbers[0]);
    cout << maxValue << '\n';
    cout << minValue;
    return 0;
}