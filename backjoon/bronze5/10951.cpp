#include <iostream>
using namespace std;
int main(){
    int a, b;
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> a >> b;
    while(!cin.eof()){
        cout << a+b << "\n";
        cin >> a >> b;
    }
    return 0;
}