#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    getline(cin, s);
    while(!cin.eof()){
        cout << s << '\n';
        getline(cin, s);
    }
    return 0;
}