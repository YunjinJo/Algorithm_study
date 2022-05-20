// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// 오픈소스 컨트리뷰션 사전과제
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int buy = prices[0];
        for(int i = 1; i < prices.size(); i++)
        {
            buy = min(buy, prices[i]);
            //if(buy != prices[i])
            profit = max(profit, prices[i] - buy);
        }

        return profit;
    }
};


int main(void)
{
    Solution sol;
    int x;
    clock_t start, end;
    double result;
    vector<int> v;
    v.push_back(7);
    v.push_back(1);
    v.push_back(5);
    v.push_back(3);
    v.push_back(6);
    v.push_back(4);
    start = clock();
    x = sol.maxProfit(v);
    end = clock();
    result = (double)(end - start);
    cout << result << '\n';
    cout << x;
    return 0;
}