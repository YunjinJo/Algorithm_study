#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    bool flag = true;
    while(flag){
        vector <int> tri;
        for(int i = 0; i < 3; i++){
            int temp;
            cin >> temp;
            tri.push_back(temp);
        }

        sort(tri.begin(), tri.end());
        int a = tri[0];
        int b = tri[1];
        int c = tri[2];

        if(a == 0 && b == 0 && c == 0){
            flag = false;
            break;
        }

        if(a * a + b * b == c * c){
            cout << "right" << '\n';
        }
        else{
            cout << "wrong" << '\n';
        }
    }
    return 0;
}