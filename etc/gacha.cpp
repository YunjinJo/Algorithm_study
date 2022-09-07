/*

2.5% 확률로 3성 캐릭터가 나오는 모바일 가챠 게임을 하다가 
200번 연속으로 뽑아도 3성 캐릭터가 안 나오길래 현타가 왔습니다...
유저 전체로 보면 확률이 2.5%가 맞을지 몰라도 체감상 느끼는 확률은 훨씬 낮아서
200번 연속으로 가챠를 할 때, 3성 캐릭터를 최소 5명은 반드시 주도록 하면 3성이 나올 확률이 몇%가 될지 궁금해 만들어 보았습니다.

조건
1. 3성 캐릭터는 2.5%, 2성 캐릭터는 18.5%, 1성 캐릭터는 79%의 확률로 뽑힌다.
2. 200연차에 도달하였는데 뽑힌 3성 캐릭터가 5명보다 적으면 마지막에 뽑히는 캐릭터는 무조건 3성이다.
ex) 3성 캐릭터 2번 나옴 -> 198, 199, 200번째 뽑는 가챠는 무조건 3성 확정
3. 이를 여러번 반복하여 확률을 계산한다.

*/

#include <bits/stdc++.h>
using namespace std;

struct User
{
    int char_pool[200];
    int star3;
    int star2;
    int star1;
};

int gatcha(User user)
{
    int star3 = 0;
    int star2 = 0;
    int star1 = 0;
    
}


int main()
{
    struct gacha USERPOOL[5];
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(1,3);
    
}