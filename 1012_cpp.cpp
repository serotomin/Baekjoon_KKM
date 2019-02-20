#include <iostream>
#include <string.h>
using namespace std;

int dy[4] = { 1,-1,0,0 }; // dy�� ���� ���� ��ġ�� ��,�Ͽ� ���� ���� Ȯ��
int dx[4] = { 0,0,1,-1 }; // dx�� ���� ���� ��ġ�� ��,�쿡 ���� ���� Ȯ��
int M, N, K; // M : ���� ���� ũ��, N : ���� ���� ũ��, K : ������ ��
int arr[50][50] = { 0 }; // MAP�� ũ��
int visited[50][50] = { 0 };

void dfs(int y, int x) {

	for (int i = 0; i < 4; i++) 
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		//if (ny < 0 || ny >= N || nx < 0 || nx >= M) //���� ������ ����ٸ� continue.
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

	memset(ans, 0, sizeof(ans)); // ans�� 0���� �ʱ�ȭ

	for (int testCase = 0; testCase<T; testCase++) {
		scanf("%d %d %d", &M, &N, &K);

		memset(arr, 0, sizeof(arr)); // int..�ڷ��� ũ��(4byte)���� arr �迭�� 0���� �ʱ�ȭ
		memset(visited, 0, sizeof(visited)); // int..�ڷ��� ũ��(4byte)���� visited �迭�� 0���� �ʱ�ȭ
	
		
		//int ans = 0; //������ ����

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
		cout << ans[i] << endl; // testcase�� ���������� ��� 
	}
	return 0;
}
