#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

int main() {

  //Please Enter Your Code Here
  int cnt = 0;
  string str1;
  string str2;
  
  getline(cin, str1);
  
  char previous = str1[0];
  cnt++;
  for(int i = 1; i < str1.size(); i++)
  {
    if(previous != str1[i])
    {
      if(cnt == 1)
      {
        str2.push_back(previous);
      }
      else
      {
        string strCnt = to_string(cnt);
        str2.append(strCnt);
        str2.push_back(previous);
      }
      
      previous = str1[i];
      cnt = 1;
    }
    
    else
    {
      cnt++;
    }
  }
  if(cnt == 1)
      {
        str2.push_back(previous);
      }
      else
      {
        string strCnt = to_string(cnt);
        str2.append(strCnt);
        str2.push_back(previous);
      }
  
  
  cout << str2;
  return 0;
}