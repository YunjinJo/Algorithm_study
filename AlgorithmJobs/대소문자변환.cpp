#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

int main() {

  //Please Enter Your Code Here
  string str;
  getline(cin, str);
  for(int i = 0; i < str.size(); i++)
  {
    
    if(0x41 <= str[i] && str[i] <= 0x5a)
    {
      str[i] += 0x20;
    }
    else if(0x61 <= str[i] && str[i] <= 0x7a)
    {
      str[i] -= 0x20;
    }
  }
  
  cout << str;

  return 0;
}