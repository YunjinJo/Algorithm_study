/*
<N x M> 크기 직사각형 맵, 각 칸은 <육지 또는 바다>
각 칸을 (A, B)로 나타내고 A는 북쪽으로 떨어진 칸, B는 서쪽으로 떨어진 칸의 개수
캐릭터는 동서남북으로 움직인다.
<바다로 되어 있는 칸은 이동 불가>

캐릭터 움직임 메뉴얼
1. 현재 위치에서 현재 방향 기준 <왼쪽부터 반시계 방향>으로 차례대로 갈 곳을 정한다.
2. 왼쪽에 가보지 않은 칸이 존재하면 <왼쪽으로 회전한 후, 한 칸 전진>한다.
가보지 않은 칸이 없으면 <왼쪽 방향으로 회전>만 하고 1단계로 돌아간다.
3. 만약 네 방향 모두 이미 가본 칸이거나 바다로 되어 있는 칸인 경우, 
바라보는 <방향을 유지한 채 한 칸 뒤로> 가고 1단계로 돌아간다.
<뒤가 바다인 경우 멈춘다>.

<해당 캐릭터가 방문한 칸의 수를 출력>
단 0: 북, 1: 동, 2: 남, 3: 서
0: 육지, 1: 바다

input
4 4      4x4 맵
1 1 0    (1, 1)위치에 북쪽을 바라보고 서 있는 캐릭터
1 1 1 1  바다 바다 바다 바다
1 0 0 1  바다 육지 육지 바다
1 1 0 1  바다 바다 육지 바다
1 1 1 1  바다 바다 바다 바다

output
3
*/


#include <bits/stdc++.h>
using namespace std;

int current_face = 0;

// 맵 크기   
int N = 0;
int M = 0;

    //현재 위치
int current_x = 0;
int current_y = 0;
   

    //맵
int d[50][50]; // 지나간 지역
int arr[50][50];

    // 방향
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int cnt = 1; // 카운터
int turn = 0;

void turn_left()
{
    current_face -= 1;
    if(current_face == -1)
    {
        current_face = 3;
    }
    
}

int main()
{
    cout << "맵 크기를 입력해주세요." << '\n';
    cin >> N >> M;
    //cin.ignore();

    cout << "캐릭터의 위치와 방향을 입력해주세요." << '\n';
    cin >> current_x >> current_y >> current_face;
    //cin.ignore();
    d[current_x][current_y] = 1;

    cout << "맵을 입력해주세요," << '\n';
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            int x;
            cin >> x;
            arr[i][j] = x;
        }
    }
    cin.ignore();

    while (true)
    {
        turn_left(); // 왼쪽으로 회전
        int nx = current_x + dx[current_face];
        int ny = current_y + dy[current_face];

        // 앞에 가보지 않은 칸이 있는 경우
        if(d[nx][ny] == 0 && arr[nx][ny] == 0)
        {
            d[nx][ny] = 1;
            current_x = nx;
            current_y = ny;
            cnt += 1;
            turn = 0;
            continue;
        }

        // 회전한 이후 앞에 가보지 않은 칸이 없거나 바다인 경우
        else turn += 1;

        // 네 방향 모두 갈 수 없는 경우
        if(turn == 4)
        {
            nx = current_x - dx[current_face];
            ny = current_y - dy[current_face];

            //뒤로 이동
            if(arr[nx][ny] == 0)
            {
                current_x = nx;
                current_y = ny;
            }

            // 뒤가 바다로 막힌 경우
            else break;
            turn = 0;
        }
    }
    
    cout << cnt << '\n';
}

/*
#include<bits/stdc++.h>
using namespace std;

int n, m, x, y, direction;

int d[50][50];
int arr[50][50];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void turn_left()
{
    direction -= 1;
    if(direction == -1) direction = 3;
}

int main(void)
{
    cin >> n >> m;
    cin >> x >> y >> direction;
    d[x][y] = 1;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            int x;
            cin >> x;
            arr[i][j] = x;
        }
    }


    int cnt = 1;
    int turn_time = 0;
    while (true)
    {
        turn_left();
        int nx = x + dx[direction];
        int ny = y + dy[direction];

        if(d[nx][ny] == 0 && arr[nx][ny] == 0)
        {
            d[nx][ny] = 1;
            x = nx;
            y = ny;
            cnt += 1;
            turn_time = 0;
            continue;
        }
        else turn_time += 1;

        if(turn_time == 4)
        {
            nx = x - dx[direction];
            ny = y - dy[direction];
            if(arr[nx][ny] == 0)
            {
                x = nx;
                y = ny;
            }
            else break;
            turn_time = 0;
        }
    }
    

    cout << cnt << '\n';
}
*/