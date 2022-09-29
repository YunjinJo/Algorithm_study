#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main() {
  int n;
  string command;
  queue <int> q;
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> command;
    if(command == "push"){
        int temp;
        cin >> temp;
        q.push(temp);
    }
    else if(command == "front"){
        if(q.empty()){
            cout << "-1" << '\n';
        }
        else{
            cout << q.front() << '\n';
        }
    }
    else if(command == "back"){
        if(q.empty()){
            cout << "-1" << '\n';
        }
        else{
            cout << q.back() << '\n';
        }
    }
    else if(command == "size"){
        cout << q.size() << '\n';
    }
    else if(command == "empty"){
        cout << q.empty() << '\n';
    }
    else if(command == "pop"){
        if(q.empty()){
            cout << "-1" << '\n';
        }
        else{
            int temp = q.front();
            cout << temp << '\n';
            q.pop();
        }
    }
  }
  return 0;
}