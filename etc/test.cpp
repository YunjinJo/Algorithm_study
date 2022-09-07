
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s1 = "()";
    string s2 = "}";
    string s3 = "(]";
    const char pOpens[] = {'(', '{', '['};
    const char pClosed[] = {')', '}', ']'};
    vector<char> v;

    v.push_back(s2.at(0));
    char i = (v.back() + 0x02);
        cout << i << '\n';

    return 0;
}