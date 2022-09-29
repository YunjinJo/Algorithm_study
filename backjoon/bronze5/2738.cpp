#include <iostream>
#include <vector>
using namespace std;
const int MAX = 101;

int main(){
    int n, m;
    vector <int> v1[MAX];
    vector <int> v2[MAX];
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int temp;
            cin >> temp;
            v1[i].push_back(temp);
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int temp;
            cin >> temp;
            v2[i].push_back(temp);
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            v1[i][j] += v2[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << v1[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}