// https://leetcode.com/problems/valid-parentheses/
// stack 이용
// 오픈소스 컨트리뷰션 사전과제
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s1 = "()";
    string s2 = "(){}[]";
    string s3 = "(]";
    const char pClosed[] = {')', '}', ']'};
    stack<char> st;
    int i = 1;
    char x1;
    char x2;

    st.push(s2.at(0));

    cout << s2.size() << '\n';

    

    while (i < s2.size())
    {
        if(st.size() != 0) // heap buffer overflow 방지
        {
            if(st.top() == '}' || st.top() == ']')
            {

            }
            else
            {
                x1 = (st.top()) + 0x01; // '('과 ')'은 아스키 코드표 상에서 0x01 차이
                x2 = x1 + 0x01; // '{', '}'과 '[', ']'은 0x02 차이
            }
            
        }
        // 괄호가 맞는 경우
        if(x1 == s2.at(i) || x2 == s2.at(i))
        {
            st.pop();
            i++;
            cout << i << '\n';
        }
        else
        {
            st.push(s2.at(i));
            i++;
        }
        
    } 

    if(st.size() == 0)
    {
        cout << "괄호 매칭" << '\n';
    }
    else
        cout << "괄호 매칭 실패" << '\n';

    return 0;
}