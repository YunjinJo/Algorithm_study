#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int x, y, w, h;
    cin >> x >> y >> w >> h;

    int goDown, goRight, goUp, goLeft;
    goUp = y;
    goLeft = x;
    goDown = h - y;
    goRight = w - x;

    int answer;
    answer = min(goUp, goLeft);
    answer = min(answer, goDown);
    answer = min(answer, goRight);
    cout << answer;
  return 0;
}