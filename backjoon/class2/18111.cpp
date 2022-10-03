#include <iostream>
#include <cstdio>
#include <memory.h>
using namespace std;
const int WLMAX = 501;
int map[WLMAX][WLMAX];
int n, m, b;
int answerTime = 0x7f7f7f7f;
int answerHeight = 0;
void getResult(){
    
    // 빈공간, 채워진 공간 비교
    for(int k = 0; k <= 256; k++){
        int fill = 0;
        int remove = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int height = map[i][j] - k;
                if(height > 0) remove += height; // 지운 블록의 개수
                else if(height < 0) fill -= height; // 채워야 하는 블록의 개수, height가 음수이므로 뺀다
            }
        }

        // 지운 블록 + 인벤토리에 있는 블록 >= 채워야 하는 블록의 개수
        if(remove + b >= fill){
            int time = remove * 2 + fill;
            if(answerTime >= time){
                answerTime = time;
                answerHeight = k;
            }
        }
    }
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> b;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int height;
            cin >> height;
            map[i][j] = height;
        }
    }
    getResult();
    cout << answerTime << ' ' << answerHeight;
    return 0;
}