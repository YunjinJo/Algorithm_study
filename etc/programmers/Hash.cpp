// 문제 지문을 읽고 요구사항 정확히 이해하기
// 완주하지 못한 선수
// 마라톤에 참가한 선수의 수  1 <= n <= 100,000 -> n에 비례하거나 nlogn 정도의 복잡도면 좋다!
// 참여한 선수의 이름이 담긴 배열 participant, 완주한 선수들의 이름이 담긴 배열 completion
// completion의 길이는 participant의 길이보다 1 작다. -> 단 한명의 선수를 제외하고 모두 완주
// 참가자 중에는 동명이인이 있을 수 있다. -> 문제의 핵심
// 완주하지 못한 선수의 이름을 return

// 어떤 자료구조를 선택하냐에 따라 알고리즘이 달라진다.
// 이름 대신 번호가 주어졌다면? -> 선형 배열(너무 배열이 커짐)
// 문자열로 접근할 수 있는 좋은 자료구조? -> 해시(Hash) 
// 사람 이름 (Key)와 해시 테이블(위치 저장 공간)을 이용
// 우연히 다른 Key가 같은 해시 테이블에 매핑되는 경우? -> 충돌 (collision) -> 옆에 다른 버킷을 만들어 해결

// ["mislav", "stanko", "mislav", "ana"] participant, 하나씩 더함
// Key       HashTable
// mislav -> 1 + 1
// stanko -> 1
// ana    -> 1

// ["stanko", "ana", "mislav"] completion, 하나씩 뺌
// mislav -> 1 -> return
// stanko -> 0
// ana    -> 0

// C++에는 기본적으로 HashTable을 지원하지 않음
// 하지만 C++ STL에서 이런 자주 쓰이는 자료구조를 컨테이너로 만들어둠
// std::map -> key에 의한 접근 시간 O(logN) -> (주로) binary search tree로 구현되어 있음 
// std::unordered_map -> O(1) -> hashtable로 구현되어 있음

#include <stdio.h>
#include <unordered_map>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

std::unordered_map <string, int> d; // d라는 unordered_map의 key가 string이고, value가 int이다


int main()
{
    cout << d["leo"] << endl; // 존재하지 않는 key에 대한 value는 기본값으로 정해진다. int -> 0, string -> ""
    d["leo"] = 3; // 특정 key에 대한 value 업데이트
    cout << d["leo"] << endl;

    // unordered_map 순회
    for(auto&i:d) // auto -> 알맞은 데이터 타입 추론함, 순서쌍으로 정해짐
        cout << i.first << " - " << i.second << endl; // i.first -> key, i.second -> value
    string str("leo");
    string str1("kiki");
    string str2("eden");
    vector<string> participant {"leo", "kiki", "eden"};
    vector<string> completion {"kiki", "leo"};
    cout << solution(participant, completion) << endl;
    return 0;
}

string solution(vector<string> participant, vector<string> completion){
    string answer = "";
    unordered_map<string, int> d;
    for(auto& i : participant) d[i]++; // 참석자 명단에 있는 선수의 value + 1
    for(auto& i : completion) d[i]--; // 완주자 명단에 있는 선수의 value - 1
    for(auto& i : d){
        if(i.second != 0){
             answer = i.first;
             break;
        }
           
    }
    return answer;

}