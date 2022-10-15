#include<stdio.h>
#include <math.h>
using namespace std;

const int MAX = 22;
int n;
int player[MAX][MAX];
bool check[MAX];
int minValue = 2000000001;

void DFS(int x, int pos){
    if(x == n / 2){
        int start, link;
        start = 0;
        link = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(check[i] && check[j]) start += player[i][j];
                else if(check[i] == false && check[j] == false)link += player[i][j];
            }
        }
        int temp = abs(start - link);
        if(minValue > temp) minValue = temp;
        return;
    }
    for(int i = pos; i < n; i++){
        check[i] = true;
        DFS(x + 1, i + 1);
        check[i] = false;
    }
}

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            scanf( "%d", &player[i][j]);
        }
    }
    DFS(0, 1);
    printf("%d", minValue);
    return 0;
}