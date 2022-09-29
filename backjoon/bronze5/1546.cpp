#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    double n;
    vector<double> v;
    double inputMax = 0;
    double result = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        double temp;
        cin >> temp;
        v.push_back(temp);
        if(temp > inputMax){
            inputMax = temp;
        }
    }
    for(int i = 0; i < n; i++){
        v[i] = v[i]/inputMax * 100;
        result += v[i];
    }
    cout.precision(10);
    cout << result/n;
    
    return 0;
}