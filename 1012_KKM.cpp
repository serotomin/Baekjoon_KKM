#include <string.h>
#include <cstdio>
#include <iostream>

using namespace std;

int M, N, K; // 맵의 가로 M, 세로 N, 배추가 심어져 있는 위치의 수 K
int dy[4] = { 1,-1,0,0 }; // 현재 좌표에서 상, 하의 배추 유무를 확인하는 배열
int dx[4] = { 0,0,1,-1 }; // 현재 좌표에서 좌, 우의 배추 유무를 확인하는 배열

int map[50][50] = { 0 }; // 50*50 크기의 배추밭
int visited[50][50] = { 0 };

void dfs(int y, int x)
{
	for (int i = 0; i < 4; i++) // 상,하,좌,우를 확인하기 위해 4번 반복
	{
		int ny = y + dy[i]; // ny는 현재 좌표에서 상,하를 체크하기 위한 변수
		int nx = x + dx[i]; // nx는 현재 좌표에서 좌,우를 체크하기 위한 변수
		
		if (ny < 0 || ny >= N || nx < 0 || nx >= M) //맵의 범위를 벗어났다면 continue.
			continue;

		if (map[ny][nx] && !visited[ny][nx]) //상,하,좌,우를 체크하면서 배추가 있는 곳에 방문처리가 되어있지 않으면 방문처리 후 다시 dfs
		{
			visited[ny][nx]++;
			dfs(ny, nx);
		}
	}
}
int main()
{
	int T = 0; // testCase 수
	int x, y = 0;

	cin >> T; // 테스트 케이스 개수 입력
	
	for (int n = 0; n < T; n++) // 입력받은 T(case)만큼 반복 수행 
	{

		cin >> M >> N >> K; // T만큼 반복하기 때문에 반복문 내에서 입력받음
		memset(map, 0, sizeof(map)); 
		memset(visited, 0, sizeof(visited));
		for (int i = 0; i < K; i++) // 배추가 심어져 있는 수(K)만큼 배추의 좌표를 입력 받음
		{
			cin >> x >> y; // 배추가 심어져 있는 좌표 x, y를 입력 받는다.
			map[y][x] = 1; // map에 표시할 때에는 map[y][x]에 배추가 있다는 의미로 1을 표기한다.
		}
		int result = 0;
		for (int i = 0; i < N; i++) // N은 세로길이
		{
			for (int j = 0; j < M; j++) // M은 가로길이
			{
				if (map[i][j] && !visited[i][j]) // 배추가 심어져 있는 땅(map[i][j]가 1일 때)에 방문표시가 되어 있지 않으면 조건문내로 진입
				{
					result++; // ant[n]은 현재 테스트 케이스의 배추흰지렁이의 마리 수(디폴트 0)
					visited[i][j]++; //현재 위치 방문처리
					dfs(i, j); //현재 배추가	 있는 위치에 dfs 시작
				}
			}
		}
		cout << result << endl;
	}
	return 0;
}