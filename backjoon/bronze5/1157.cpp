#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(){
    string s;
    cin >> s;
    int count[26] = {0, };
    int maxIndex = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] <= 90){
            int toNumber = s[i] - 'A';
            count[toNumber]++;
        }
        else{
            int toNumber = s[i] - 'a';
            count[toNumber]++;
        }
    }

    for(int i = 0; i < 26; i++){
        if(count[maxIndex] < count[i]){
            maxIndex = i;
        }
    }
    for(int i = 0; i < 26; i++){
        if(i != maxIndex && count[i] == count[maxIndex]){
            cout << "?";
            return 0;
        }
    }
    cout << char('A'+maxIndex);
    return 0;
}