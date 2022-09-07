#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

int main() {

  //Please Enter Your Code Here
  int cnt = 0;
  string str1;
  
  getline(cin, str1);
  
  for(int i = 0; i < str1.size()/2; i++)
  {
    if(str1[i] == str1[str1.size() - i - 1])
    {
      cnt++;
    }
  }
  if(cnt == str1.size() / 2)
  {
    cout << "YES";
  }
  else
  {
    cout << "NO";
  }
  return 0;
}