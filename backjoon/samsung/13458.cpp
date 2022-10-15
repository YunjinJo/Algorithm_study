#include <iostream>
#include <cstdio>
using namespace std;
const int MAX = 1000001;
int n, b, c;
long long int Ai[MAX];
long long int answer = 0;

void getResult(int index){
    long long int people = Ai[index];
    people -= b;
    answer++;
    if(people <= 0) return;
    else{
        answer = answer + people / c;
        if(people % c != 0) answer++;
    }
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> Ai[i];
    }
    cin >> b >> c;

    for(int i = 0; i < n; i++){
        getResult(i);
    }
    cout << answer;
    return 0;
}