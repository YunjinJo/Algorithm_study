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
    
    if(str[i] == ' ')
    {
      str[i] = 0x00;
    }
    
  }
  
  cout << str;

  return 0;
}