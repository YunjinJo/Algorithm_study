#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

vector <pair<int, int>> people; // 몸무게, 키
int n;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++){
        int weight;
        int height;
        cin >> weight >> height;
        people.push_back(make_pair(weight, height));
    }
    
    for(int i = 0; i < n; i++){
        int rank = 0;
        int w1 = people[i].first;
        int h1 = people[i].second;
        for(int j = 0; j < n; j++){
            int w2 = people[j].first;
            int h2 = people[j].second;
            if(w1 < w2 && h1 < h2){
                rank++;
            }
        }
        cout << rank + 1 << ' ';
    }

    return 0;
}