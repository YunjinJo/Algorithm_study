#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int n, m;
vector <string> v1;
vector <string> v2;
vector <string> answer;
int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        string temp;
        cin >> temp;
        v1.push_back(temp);
    }
    sort(v1.begin(), v1.end());

    for(int i = 0; i < m; i++){
        string temp;
        cin >> temp;
        if(binary_search(v1.begin(), v1.end(), temp)){
            answer.push_back(temp);
        }
    }
    
    sort(answer.begin(), answer.end());
    int answerSize = answer.size();
    cout << answerSize << '\n';
    for(int i = 0; i < answerSize; i++){
        cout << answer[i] << '\n';
    }
    return 0;
}