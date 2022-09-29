#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int repeat;
        cin >> repeat;
        string s;
        cin >> s;
        for(int j = 0; j < s.size(); j++){
            for(int k = 0; k < repeat; k++){
                cout << s[j];
            }
        }
        cout << '\n';
    }
    return 0;
}