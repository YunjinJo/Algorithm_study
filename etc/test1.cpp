#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

//여벌 체육복 빌려줌, 체격 순으로 번호, 바로 앞 또는 뒤 학생에게만 빌려줄 수 있음, 
//최대한 많은 학생이 빌릴 수 있어야 함
// 전체 학생 수 2 <= n <= 30, 도난당한 색생들의 번호 배열 lost[], 여벌 체육복 학생들 번호 배열 reserve[] 

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n - lost.size();
    for(int i = 0; i < reserve.size(); i++)
    {
        int reserveNumber = reserve.at(i);
        for(int j = 0; j < lost.size(); j++)
        {
            int lostNumber = lost.at(j);
            

            if((reserveNumber+1 == lostNumber) || (reserveNumber -1 == lostNumber))
            {
                if(i < reserve.size()-1)
                {
                    if(reserve.at(i+1) == lostNumber)
                    {
                    answer += 1;
                    break;
                    }
                }
                answer += 1;
                break;
            }
        }

        
    }

   /*  if(answer >= n)
        {
            answer = n;
        } */


    return answer;
}

int main()
{
    vector<int> re;
    vector<int> lo;
    re.push_back(2);
    re.push_back(3);
    re.push_back(4);
    //lo.push_back(2);
    lo.push_back(3);
    lo.push_back(4);
    cout << solution(5, lo, re) << "\n";
}