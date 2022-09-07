#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

int main() {

  //Please Enter Your Code Here
  string str1;
  string str2;
  
  getline(cin, str1);
  
  for(int i = str1.size() - 1; i >= 0; i--)
  {
    str2.push_back(str1[i]);
  }
  cout << str2;
  return 0;
}