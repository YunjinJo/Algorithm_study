#include <iostream>
#include <memory.h>
#include <queue>
using namespace std;

const int MAX = 1002;
bool check[MAX];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(check, 0, sizeof(check));

    int n, k;
    queue <int> q;
    cin >> n >> k;
    
    for(int i = 1; i <= n; i++){
        q.push(i);
    }
    cout << "<";
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < k - 1; j++){
            int temp;
            temp = q.front();
            q.pop();
            q.push(temp);
        }
        cout << q.front() << ", ";
        q.pop();
    }
    cout << q.front() << ">";
    return 0;
}