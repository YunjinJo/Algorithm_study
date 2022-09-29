#include <iostream>
using namespace std;
int main(){
    bool flag = true;
    int a, b;
    while (flag){
        cin >> a >> b;
        if(a == 0 && b == 0){
            flag = false;
            break;
        }
        cout << a+b << "\n";
    } 
    return 0;
}