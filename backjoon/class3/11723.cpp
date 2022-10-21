#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int m;
int bitMasking = 0;


int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> m;
    for(int i = 0; i < m; i++){
        int x;
        string s;
        cin >> s;
        if(s == "add"){
            cin >> x;
            bitMasking |= (1<<x); // 0000 0000 | 0000 0010
        }
        else if(s == "remove"){
            cin >> x;
            bitMasking &= ~(1<<x);
        }
        else if(s == "check"){
            cin >> x;
            if(bitMasking & (1<<x)){
                cout << "1\n";
            }
            else{
                cout << "0\n";
            }
        }
        else if(s == "toggle"){
            cin >> x;
            if(bitMasking & (1<<x)){
                bitMasking &= ~(1<<x);
            }
            else{
                bitMasking |= (1<<x);
            }
        }
        else if(s == "all"){
            bitMasking = (1<<21) - 1;
        }
        else if(s == "empty"){
            bitMasking = 0;
        }
    }
    return 0;
}