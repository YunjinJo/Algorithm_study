#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool cmp(pair<int,pair<int, string>> p1, pair<int, pair<int, string>> p2){
    // 나이 오름차순 정렬
    if(p1.second.first < p2.second.first){
        return true;
    }
    else if(p1.second.first > p2.second.first){
        return false;
    }
    else{
        // 가입 순서 오름차순 정렬
        if(p1.first < p2.first){
            return true;
        }
        else{
            return false;
        }
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    // 가입 순서, 나이, 이름
    vector<pair<int, pair<int, string>>> user;
    cin >> n;
    for(int i = 0; i < n;i++){
        int age;
        string name;
        cin >> age;
        cin >> name;
        user.push_back(make_pair(i,make_pair(age, name)));
    }
    sort(user.begin(), user.end(), cmp);
    for(int i = 0; i < user.size(); i++){
        cout << user[i].second.first << ' ';
        cout << user[i].second.second << ' ';
    }
    return 0;
}