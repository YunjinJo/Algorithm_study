#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    stack<int> Stack;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        if(temp != 0){
            Stack.push(temp);
        }
        else{
            Stack.pop();
        }
    }

    if(!Stack.empty()){
        int answer = 0;
        while (!Stack.empty())
        {
            answer += Stack.top();
            Stack.pop();
        }
        cout << answer;
    }
    else{
        cout << "0";
    }
  
  return 0;
}