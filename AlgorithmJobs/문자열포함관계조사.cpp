#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

int main() {

  //Please Enter Your Code Here
  string str1;
  string str2;
  getline(cin, str1);
  getline(cin, str2);
  if(str1.find(str2) <= str1.size())
  {
    cout << "YES";
  }
  else
  {
    cout << "NO";
  }
  return 0;
}