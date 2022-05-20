// https://leetcode.com/problems/truncate-sentence/description/
// 오픈소스 컨트리뷰션 사전과제
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string truncateSentence(string s, int k) {
        int space_cnt = 0;
        for(int i = 0; i < s.length(); i++)
        {
            if(s.at(i) == ' ')
            {
                space_cnt++;
                if(space_cnt == k)
                {
                    return s.substr(0, i);
                }
            }
        }
        return s;
    }
};

int main()
{
    Solution sol;
    int k = 4;
    string s = "Hello how are you Contestant";
    string answer;
    answer = sol.truncateSentence(s, k);
    cout << answer << '\n';
    return 0;
}