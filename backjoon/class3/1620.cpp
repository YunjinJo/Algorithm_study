#include <iostream>
#include <cstdio>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;
const int MAX = 1000001;
unordered_map <string, int> pokemon;
int n, m;
string arr[MAX];
int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        string temp;
        cin >> temp;
        pokemon.insert(make_pair(temp, i));
        arr[i] = temp;
    }
    
    for(int i = 0; i < m; i++){
        string input;
        cin >> input;
        if(pokemon.find(input) != pokemon.end()){
            cout << pokemon.find(input) -> second << '\n';
        }
        else{
            int num = stoi(input);
            cout << arr[num] << '\n';
        }
    }
    return 0;
}