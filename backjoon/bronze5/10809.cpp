#include <iostream>
#include <string>
#include <memory.h>
using namespace std;
const int MAX = 26;
int main(){
    string s;
    int alpha[MAX];
    memset(alpha, -1, sizeof(alpha));
    getline(cin, s);
    for(int i = 0; i < MAX; i++){
        char temp = 'a' + i;
        if(s.find(temp) != string::npos){
            alpha[i] = s.find(temp);
            cout << alpha[i] << ' ';
        }
        else{
            alpha[i] = -1;
            cout << alpha[i] << ' ';
        }
    }
    
    return 0;
}