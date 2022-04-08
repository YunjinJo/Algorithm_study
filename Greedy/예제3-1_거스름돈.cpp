/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int main()
{
    int change = 1260;
    int count = 0;
    int coinTypes[4] = {500, 100, 50, 10};

    for (int i = 0; i < 4; i++)
    {
        int coin = coinTypes[i]; // i = 0 -> 500, i = 1 -> 100
        count += change / coin; // 거스름돈을 500, 100...으로 나눈 몫을 더함
        change %= coin; // 거스름돈을 500, 100...으로 나눈 나머지를 잔돈으로 설정 1260 -> 260
    }
    cout << count << '\n';
    
}
