#include <iostream>
#include <string>
using namespace std;

int main(){
    int n;
    string s;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s;
        cout << s.front() << s.back() << '\n';
    }
    return 0;
}