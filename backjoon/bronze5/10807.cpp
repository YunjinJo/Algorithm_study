#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n,v;
    int cnt = 0;
    vector <int> arr;
    cin >> n;
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
    cin >> v;
    for(int i = 0; i < n; i++){
        if(v == arr[i])
            cnt++;
    }
    cout << cnt;
    return 0;
}