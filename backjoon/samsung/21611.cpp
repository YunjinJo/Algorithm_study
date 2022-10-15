#include <iostream>
#include <cstdio>
using namespace std;

const int map_MAX = 52;
const int dx[] = { 0, 0, -1, 1 };
const int dy[] = { -1, 1, 0, 0 };

int n, m, ret;
int line_size;
int line[2500];
int map[map_MAX][map_MAX];

void destroy_by_rule(int d, int s) { // ����, ����
	int cy = n / 2;
	int cx = n / 2;

	for (int i = 1; i <= s; i++) {
		int ny = cy + (dy[d] * i);
		int nx = cx + (dx[d] * i);
		map[ny][nx] = 0; // �ı�
	}
}

void convert_to_line() {
	// �߾�
	int cy = n / 2;
	int cx = n / 2;

	// 2���� ��ĵ�ϰ� dist ����, ���������� 3��
	int loop_count = 2;
	// �� �� �� ��
	int ddy[] = {0, 1, 0, -1};
	int ddx[] = {-1, 0, 1, 0};
	int d = 0; // ���� �ε���

	line_size = 0; // �ε���

	for (int dist = 1; dist < n; dist++) { // Ž���� ����
		if (dist == n - 1) {
			loop_count = 3; // �������� 3��
		}

		for (int i = 0; i < loop_count; i++) {
			for (int j = 0; j < dist; j++) {
				cy += ddy[d];
				cx += ddx[d];
				// 0�� �ǳʶ�
				if(map[cy][cx] != 0)
					line[line_size++] = map[cy][cx];
			}
			d = (d + 1) % 4;
		}
	}
	
}

int destroy_by_rule() {
	int point = 0;
	int count = 1;

	for (int i = 1; i < line_size; i++) {
		if (line[i - 1] == line[i]) {
			count++;
		}
		else {
			if (count >= 4) {
				for (int j = 1; j <= count; j++) {
					point += line[i - j];
					line[i - j] = 0;
				}
			}
			count = 1;
		}
	}
	if (count >= 4) {
		for (int j = 1; j <= count; j++) {
			point += line[line_size - j];
			line[line_size - j] = 0;
		}
	}
	ret += point;
	return point;
}

void remove_zero() {
	// 1���� �迭 0 ����
	int back_size = 0;
	int back[2500] = { 0, };
	for (int i = 0; i < line_size; i++) {
		if (line[i] != 0) {
			back[back_size++] = line[i];
		}
	}
	for (int i = 0; i < back_size; i++) {
		line[i] = back[i];
	}
	line_size = back_size;
}

void change_by_rule() {
	int back_size = 0;
	int back[2500] = { 0, };
	int count = 1;
	
	for (int i = 1; i < line_size; i++) {
		if (line[i - 1] == line[i]) {
			count++;
		}
		else {
			if (back_size < n * n - 2) {
				back[back_size++] = count;
				back[back_size++] = line[i - 1];
			}
			count = 1;
		}
	}

	if (line_size > 0 && back_size < n * n - 2) {
		back[back_size++] = count;
		back[back_size++] = line[line_size - 1];
	}

	for (int i = 0; i < back_size; i++) {
		line[i] = back[i];
	}
	line_size = back_size;
}

void convert_to_mat() {
	// �߾�
	int cy = n / 2;
	int cx = n / 2;

	// 2���� ��ĵ�ϰ� dist ����, ���������� 3��
	int loop_count = 2;
	// �� �� �� ��
	int ddy[] = { 0, 1, 0, -1 };
	int ddx[] = { -1, 0, 1, 0 };
	int d = 0; // ���� �ε���

	int cur = 0; // 1���� �迭 �ε���

	for (int dist = 1; dist < n; dist++) { // Ž���� ����
		if (dist == n - 1) {
			loop_count = 3; // �������� 3��
		}

		for (int i = 0; i < loop_count; i++) {
			for (int j = 0; j < dist; j++) {
				cy += ddy[d];
				cx += ddx[d];
				if (cur < line_size) {
					map[cy][cx] = line[cur++];
				}
				else {
					map[cy][cx] = 0;
				}
				
			}
			d = (d + 1) % 4;
		}
		
	}
}

void show() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	ret = 0;

	
	//cout << '\n';
	for (int i = 0; i < m; i++) {
		int d, s;
		cin >> d >> s;
		destroy_by_rule(d - 1, s);
		//show();
		convert_to_line();
		while (destroy_by_rule() != 0) {
			remove_zero();
		}
		remove_zero();
		change_by_rule();
		convert_to_mat();
		//show();
	}
	cout << ret;
	
	return 0;
}