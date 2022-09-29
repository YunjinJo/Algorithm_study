#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool cond(string a, string b){
    if(a.size() > b.size()){
        return 0;
    }
    else if(a.size() < b.size()){
        return 1;
    }
    else{
        if(a >= b){
            return 0;
        }
        else{
            return 1;
        }
    }
}

int main() {
    int n;
    vector<string> v;
    cin >> n;
    for(int i = 0; i < n; i++){
        string temp;
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(), v.end(), cond);
    cout << v[0] << '\n';
    for(int i = 1; i < n; i++){
        if(v[i-1] != v[i])
            cout << v[i] << '\n';
    }
  return 0;
}