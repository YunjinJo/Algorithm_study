#include <iostream>
#include <cstdio>
#include <memory.h>
using namespace std;

struct CLOUD
{
	int y, x;
};

// ←, ↖, ↑, ↗, →, ↘, ↓, ↙
const int dy[] = {0, -1, -1, -1, 0, 1, 1, 1};
const int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};

const int MAX = 52;

int n, m;
int water[MAX][MAX];
int cloud_map[MAX][MAX];
int cloud_size;
CLOUD cloud[2500];


void increase_water() {
	for (int i = 0; i < cloud_size; i++) {
		water[cloud[i].y][cloud[i].x]++;
	}
}
void delete_cloud() {
	memset(cloud_map, 0, sizeof(cloud_map));
	for (int i = 0; i < cloud_size; i++) {
		cloud_map[cloud[i].y][cloud[i].x] = 1;
	}
	cloud_size = 0;
}
void copy_bug() {
	int increase_water[MAX][MAX] = { 0, };
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			if (cloud_map[y][x] == 1) {
				int count = 0;
				// 대각선으로 서칭
				for (int d = 1; d < 8; d += 2) {
					int ny = y + dy[d];
					int nx = x + dx[d];
					if (ny < 0 || ny >= n || nx < 0 || nx >= n) {
						continue;
					}
					if (water[ny][nx] >= 1) {
						count++;
					}
				}
				increase_water[y][x] = count;
			}
		}
	}
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			water[y][x] += increase_water[y][x];
		}
	}
}

void create_cloud(int y, int x) {
	cloud[cloud_size].y = y;
	cloud[cloud_size].x = x;
	cloud_size++;
}

void generate_cloud() {
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			if (water[y][x] >= 2 && cloud_map[y][x] == 0) {
				create_cloud(y, x);
				water[y][x] -= 2;
			}
		}
	}
}

void move_cloud(int d, int s) {
	int dist_y = (dy[d] * s) + (n * 50);
	int dist_x = (dx[d] * s) + (n * 50);

	for (int i = 0; i < cloud_size; i++) {
		cloud[i].y = (dist_y + cloud[i].y) % n;
		cloud[i].x = (dist_x + cloud[i].x) % n;
	}
}



void init_cloud() {
	create_cloud(n - 2, 0);
	create_cloud(n - 2, 1);
	create_cloud(n - 1, 0);
	create_cloud(n - 1, 1);
}

int main() {
	cin >> n >> m;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			cin >> water[y][x];
		}
	}
	init_cloud();
	
	for (int i = 0; i < m; i++) {
		int d, s;
		cin >> d >> s;
		move_cloud(d - 1, s);
		increase_water();
		delete_cloud();
		copy_bug();
		generate_cloud();
	}

	int ret = 0;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			ret += water[y][x];
		}
	}
	cout << ret;

	return 0;
}