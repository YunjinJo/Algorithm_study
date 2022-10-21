#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector <long long int> v1; // 정렬할 벡터
vector <long long int> v2; // 원본 벡터

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        v1.push_back(temp);
        v2.push_back(temp);
    }
    sort(v1.begin(), v1.end());
    v1.erase(unique(v1.begin(), v1.end()), v1.end()); // 중복값 제거
    for(int i = 0; i < n; i++){
        // v2[i]와 같거나 큰 주소값
        cout << lower_bound(v1.begin(), v1.end(), v2[i]) - v1.begin() << ' ';
    }

    return 0;
}