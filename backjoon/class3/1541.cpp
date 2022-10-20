// -가 한번이라도 나오면 뒤에 있는 수를 모두 뺀다
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

const int MAX = 100;
int input[MAX];
char op[MAX];

int inputSize = 0;
int opSize = 0;

int answer = 0;

void show(){
    cout << '\n';
    for(int i = 0; i < inputSize; i++){
        cout << input[i] << ' ';
    }
    cout << '\n';

    for(int i = 0; i < opSize; i++){
        cout << op[i] << ' ';
    }
    cout << '\n';
}

void getNum(){
   bool isMinus = false; // -가 한번이라도 나왔는가?
   answer = input[0]; // 첫번째 수
    for(int i = 0; i < opSize; i++){
        if(op[i] == '-'){
            isMinus = true;
        }
        if(op[i] == '-' || op[i] == '+'){
            if(isMinus){
                answer -= input[i + 1];
            }
            else{
                answer += input[i + 1];
            }
        }
    }
}


int main(){
    string s;
    getline(cin, s);
    int sSize = 0;
    sSize = s.size();
    string temp;
    for(int i = 0; i < sSize; i++){
        if(s[i] == '+'){
            input[inputSize++] = stoi(temp);
            temp = "";
            op[opSize++] = '+';
        }
        else if(s[i] == '-'){
            input[inputSize++] = stoi(temp);
            temp = "";
            op[opSize++] = '-';
        }
        else{
            temp += s[i];
        }
    }
    // 마지막 숫자 추가
    input[inputSize++] = stoi(temp);
    temp = "";
    
    getNum();
    cout << answer;
    return 0;
}