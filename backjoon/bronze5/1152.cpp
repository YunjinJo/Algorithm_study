#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(){
    int cnt = 0;
    string temp;
    getline(cin, temp);
    if(temp.front() == ' ') cnt--;
    if(temp.back() == ' ') cnt--;
    for(int i = 0; i < temp.size(); i++){
        if(temp[i] == ' '){
            cnt++;
        }
    }
    
    cout << cnt + 1;
    return 0;
}