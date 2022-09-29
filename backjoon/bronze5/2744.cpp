#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    getline(cin, s);
    for(int i = 0; i < s.size(); i++){
        if(s[i] >= 'a' && s[i] <= 'z'){
            s[i] = toupper(s[i]);
            cout << s[i];
        }
        else{
            s[i] = tolower(s[i]);
            cout << s[i];
        }
    }
    return 0;
}