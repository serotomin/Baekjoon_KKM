#include <iostream>
#include <string.h>
using namespace std;

int dy[4] = { 1,-1,0,0 }; // dy를 통해 현재 위치의 상,하에 배추 유무 확인
int dx[4] = { 0,0,1,-1 }; // dx를 통해 현재 위치의 좌,우에 배추 유무 확인
int M, N, K; // M : 맵의 가로 크기, N : 맵의 세로 크기, K : 배추의 수
int arr[50][50] = { 0 }; // MAP의 크기
int visited[50][50] = { 0 };

void dfs(int y, int x) {

	for (int i = 0; i < 4; i++) 
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		//if (ny < 0 || ny >= N || nx < 0 || nx >= M) //맵의 범위를 벗어났다면 continue.
		//	continue;

		if (arr[ny][nx] && !visited[ny][nx]) {
			visited[ny][nx]++;
			dfs(ny, nx);
		}
	}
}
int main() {
	int T, x, y;
	int ans[5];
	cin >> T;

	memset(ans, 0, sizeof(ans)); // ans를 0으로 초기화

	for (int testCase = 0; testCase<T; testCase++) {
		scanf("%d %d %d", &M, &N, &K);

		memset(arr, 0, sizeof(arr)); // int..자료형 크기(4byte)마다 arr 배열을 0으로 초기화
		memset(visited, 0, sizeof(visited)); // int..자료형 크기(4byte)마다 visited 배열을 0으로 초기화
	
		
		//int ans = 0; //지렁이 개수

		for (int i = 0; i<K; i++) {
			scanf("%d %d", &x, &y);
			arr[y][x] = 1; 
		}

		for (int i = 0; i<N; i++)
			for (int j = 0; j<M; j++)
				if (arr[i][j] && !visited[i][j]) 
				{

					ans[testCase]++;
					visited[i][j]++;
					dfs(i, j);

				}
		//cout << ans << endl;
	}
	for (int i = 0; i < T; i++)
	{
		cout << ans[i] << endl; // testcase별 배추지렁이 출력 
	}
	return 0;
}
