#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
  int n;
  string command;
  stack <int> Stack;
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> command;
    if(command == "push"){
        int temp;
        cin >> temp;
        Stack.push(temp);
    }
    else if(command == "top"){
        if(Stack.empty()){
            cout << "-1" << '\n';
        }
        else{
            cout << Stack.top() << '\n';
        }
    }
    else if(command == "size"){
        cout << Stack.size() << '\n';
    }
    else if(command == "empty"){
        cout << Stack.empty() << '\n';
    }
    else if(command == "pop"){
        if(Stack.empty()){
            cout << "-1" << '\n';
        }
        else{
            int temp = Stack.top();
            cout << temp << '\n';
            Stack.pop();
        }
    }
  }
  return 0;
}