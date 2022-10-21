#include <iostream>
#include <cstdio>
using namespace std;
const int MAX = 129;
int n;
int arr[MAX][MAX];
int white = 0;
int blue = 0;

void recur(int sX, int sY, int eX, int eY){
    bool isDiff = false;
    if(sX == eX && sY == eY) isDiff == false;
    if(sX > eX || sY > eY) return;
    if(isDiff == false){
        int curValue = arr[sY][sX];
        for(int i = sY; i < eY; i++){
            if(isDiff) break;
            for(int j = sX; j < eX; j++){
                if(arr[i][j] != curValue){
                    isDiff = true;
                    break;
                }
            }
        }
    }


    if(isDiff == false){
        int curValue = arr[sY][sX];
        if(curValue == 1) blue++;
        else white++;
        return;
    }
    else{
        int midX = (sX + eX) / 2;
        int midY = (sY + eY) / 2;
        recur(sX, sY, midX, midY);
        recur(midX, sY, eX, midY);
        recur(sX, midY, midX, eY);
        recur(midX, midY, eX, eY);
    }
}


int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }
    recur(0,0,n,n);
    cout << white << '\n' << blue;
    return 0;
}