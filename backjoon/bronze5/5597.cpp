#include <iostream>
#include <vector>
using namespace std;
int main(){
    bool check[31] = {0, };
    for(int i = 0; i < 28; i++){
        int temp;
        cin >> temp;
        check[temp] = true;
    }

    for(int i = 1; i <= 30; i++){
        if(check[i] == false)
            cout << i << '\n';
    }
    return 0;
}