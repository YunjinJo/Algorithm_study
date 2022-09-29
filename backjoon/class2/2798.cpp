#include <iostream>
#include <memory.h>
#include <vector>
using namespace std;

int n, m;
vector<int> a;
vector <int> cards;
bool check[101];

// i = 0, i = 1, i = 2
void result(int cnt, int sum){
    int repeat = cards.size();
    if(cnt > 2){
        a.push_back(sum);
    }
    else{
        for(int i = 0; i < repeat; i++){
            if(check[i]){
                continue;
            }
            else{
                check[i] = true;
                result(cnt + 1, sum + cards[i]);
                check[i] = false;
            }
        }
    }
}

int main(){
    
    memset(check, 0, sizeof(check));
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        cards.push_back(temp);
    }
    result(0, 0);

    int answer = 0;
    for(int i = 0; i < a.size(); i++){
        if(answer < a[i] && a[i] <= m)
            answer = a[i];
    }
    cout << answer;
    return 0;
}