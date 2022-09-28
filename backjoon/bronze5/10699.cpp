#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
    time_t timer = time(NULL);
    struct tm* t = localtime(&timer);
    cout << t->tm_year + 1900 << "-";
    int mon = t->tm_mon + 1;
    if(mon < 10){
        string temp;
        temp = "0" + to_string(mon);
        cout << temp << "-";
    }
    else
        cout << t->tm_mon + 1 << "-";
    cout << t->tm_mday;
}