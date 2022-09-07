
#include <bits/stdc++.h>
using namespace std;
int multiply(int current, int add)
{
    int temp = current;
    temp *= 10;
    temp += add;
    return temp;
}


int solution(string s) {
    int answer = 0;
    string number = s;
    while(number != "")
    {
        if(number.front() == 'z')
    {
        answer = multiply(answer, 0);
        number = number.substr(4);
    }
    else if(number.front() == 'o')
    {
        answer = multiply(answer, 1);
        number = number.substr(3);
    }
    else if(number.front() == 'e')
    {
        answer = multiply(answer, 8);
        number = number.substr(5);
    }
    else if(number.front() == 'n')
    {
        answer = multiply(answer, 9);
        number = number.substr(4);
    }

    else if(number.front() == 's')
    {
        if(number.find("six"))
        {
            answer = multiply(answer, 6);
            number = number.substr(3);
        }
        else
        {
        answer = multiply(answer, 7);
        number = number.substr(5);
        }
        
    }

    
    else
    {
        char temp = number.front();
        int temp1 = temp -'0';
        answer = multiply(answer, temp1);
        number = number.substr(1);
    }

    }
    
    

    return answer;
}





int main()
{
   string s = "one4seveneight";
   cout << solution(s) << "\n";
}