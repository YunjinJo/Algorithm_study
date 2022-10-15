#include <cstdio>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

struct Point
{
	int r, c, d;
};

const int MAX = 22;
int sea[MAX][MAX] = {0, };
int n;

int dx[] = { -1, 0, 0, 1 };
int dy[] = { 0, -1, 1, 0 };

int sharkX = 0;
int sharkY = 0;
int sharkSize = 2;
int eatCnt = 0;


int BFS() {
	int ret = 0;
	Point minPt = { sharkY, sharkX, 0 }; // 현재 상어 위치

	do {
		// 초기화
		bool visited[MAX][MAX] = { 0, };
		queue<Point> myq;
		visited[minPt.r][minPt.c] = true;
		myq.push({ minPt.r, minPt.c, 0 });
		minPt.d = INF;

		// BFS
		while (!myq.empty()) {
			Point current = myq.front();
			//cout << current.r << ' ' << current.c << '\n';
			myq.pop();

			if (current.d > minPt.d) {
				//cout << " break " << '\n';
				break;
			}
			if (sea[current.r][current.c] > sharkSize) continue; // 못먹음

			// 물고기 먹음
			if (sea[current.r][current.c] != 0 && sea[current.r][current.c] < sharkSize) {
				// 더 가까이에 있는가?
				if (current.d < minPt.d) {
					minPt = current;

				}
				else if (current.d == minPt.d) {
					// 더 위쪽에 있는가?
					if (current.r < minPt.r) {
						minPt = current;
					}
					// 더 왼쪽에 있는가?
					else if (current.r == minPt.r && current.c < minPt.c) {
						minPt = current;
					}
				}
				continue;
			}

			for (int i = 0; i < 4; i++) {
				int nr = current.r + dy[i];
				int nc = current.c + dx[i];
				if (nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
				if (visited[nr][nc]) continue;
				visited[nr][nc] = true;
				myq.push({ nr, nc, current.d + 1 });
			}
		}

		// 물고기를 먹음
		if (minPt.d != INF) {
			ret += minPt.d;
			eatCnt++;
			if (eatCnt == sharkSize) {
				sharkSize++;
				eatCnt = 0;
			}
			sea[minPt.r][minPt.c] = 0;
		}

	} while (minPt.d != INF); // 물고기 못먹음
	
	return ret;
}

int main() {
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int temp;
			cin >> temp;
			sea[i][j] = temp;
			if (temp == 9) {
				sharkY = i;
				sharkX = j;
				sea[i][j] = 0;
			}
			
		}
	}
	int answer = BFS();
	cout << answer;
	return 0;
}