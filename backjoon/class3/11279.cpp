#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

priority_queue <int> pQ;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        if(temp == 0){
            if(pQ.empty()){
                cout << "0\n";
            }
            else{
                cout << pQ.top() << '\n';
                pQ.pop();
            }
        }
        else{
            pQ.push(temp);
        }
    }
    return 0;
}