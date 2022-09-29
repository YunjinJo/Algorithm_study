#include <iostream>
#include <memory.h>
#include <vector>
using namespace std;

const int MAX = 100;
bool hotel[MAX][MAX];

int result(int height, int width, int number){
    int answer;
    int floor;
    int room;
    floor = number % height;
    room = number / height + 1;
    if(floor == 0){
        floor = height;
        room -= 1;
    }
    answer = floor;
    answer *= 100;
    answer += room;
    
    return answer;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(hotel, 0, sizeof(hotel));
    
    int t, h, w, n;
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> h >> w >> n;
        cout << result(h, w, n) << '\n';
    }
    return 0;
}