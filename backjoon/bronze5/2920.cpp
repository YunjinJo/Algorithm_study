#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    vector<int> v;
    int decide;
    for(int i = 0; i < 8; i++){
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    if(v[0] > v[1]){
        for(int i = 1; i < 8; i++){
            if(v[i - 1] < v[i]){
                cout << "mixed";
                return 0;
            }
        }
        cout << "descending";
    }

    else if(v[0] < v[1]){
        for(int i = 1; i < 8; i++){
            if(v[i - 1] > v[i]){
                cout << "mixed";
                return 0;
            }
        }
        cout << "ascending";
    }

    return 0;
}