#include <iostream>
#include <string>
using namespace std;

int main() {
  int cnt = 0;
  string str1;
  bool flag = true;
  while(flag){
    getline(cin, str1);
    if(str1 == "0"){
        flag = false;
        break;
    }
    for(int i = 0; i < str1.size() / 2; i++){
        if(str1[i] == str1[str1.size() - i - 1]){
            cnt++;
        }
    }
    if(cnt == str1.size() / 2){
        cout << "yes" << '\n';
    }
    else{
        cout << "no" << '\n';
    }
    cnt = 0;
  }
  return 0;
}