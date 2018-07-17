#include <string.h>
#include <cstdio>
#include <iostream>

using namespace std;

int M, N, K; // ���� ���� M, ���� N, ���߰� �ɾ��� �ִ� ��ġ�� �� K
int dy[4] = { 1,-1,0,0 }; // ���� ��ǥ���� ��, ���� ���� ������ Ȯ���ϴ� �迭
int dx[4] = { 0,0,1,-1 }; // ���� ��ǥ���� ��, ���� ���� ������ Ȯ���ϴ� �迭

int map[50][50] = { 0 }; // 50*50 ũ���� ���߹�
int visited[50][50] = { 0 };

void dfs(int y, int x)
{
	for (int i = 0; i < 4; i++) // ��,��,��,�츦 Ȯ���ϱ� ���� 4�� �ݺ�
	{
		int ny = y + dy[i]; // ny�� ���� ��ǥ���� ��,�ϸ� üũ�ϱ� ���� ����
		int nx = x + dx[i]; // nx�� ���� ��ǥ���� ��,�츦 üũ�ϱ� ���� ����
		
		if (ny < 0 || ny >= N || nx < 0 || nx >= M) //���� ������ ����ٸ� continue.
			continue;

		if (map[ny][nx] && !visited[ny][nx]) //��,��,��,�츦 üũ�ϸ鼭 ���߰� �ִ� ���� �湮ó���� �Ǿ����� ������ �湮ó�� �� �ٽ� dfs
		{
			visited[ny][nx]++;
			dfs(ny, nx);
		}
	}
}
int main()
{
	int T = 0; // testCase ��
	int x, y = 0;

	cin >> T; // �׽�Ʈ ���̽� ���� �Է�
	
	for (int n = 0; n < T; n++) // �Է¹��� T(case)��ŭ �ݺ� ���� 
	{

		cin >> M >> N >> K; // T��ŭ �ݺ��ϱ� ������ �ݺ��� ������ �Է¹���
		memset(map, 0, sizeof(map)); 
		memset(visited, 0, sizeof(visited));
		for (int i = 0; i < K; i++) // ���߰� �ɾ��� �ִ� ��(K)��ŭ ������ ��ǥ�� �Է� ����
		{
			cin >> x >> y; // ���߰� �ɾ��� �ִ� ��ǥ x, y�� �Է� �޴´�.
			map[y][x] = 1; // map�� ǥ���� ������ map[y][x]�� ���߰� �ִٴ� �ǹ̷� 1�� ǥ���Ѵ�.
		}
		int result = 0;
		for (int i = 0; i < N; i++) // N�� ���α���
		{
			for (int j = 0; j < M; j++) // M�� ���α���
			{
				if (map[i][j] && !visited[i][j]) // ���߰� �ɾ��� �ִ� ��(map[i][j]�� 1�� ��)�� �湮ǥ�ð� �Ǿ� ���� ������ ���ǹ����� ����
				{
					result++; // ant[n]�� ���� �׽�Ʈ ���̽��� �������������� ���� ��(����Ʈ 0)
					visited[i][j]++; //���� ��ġ �湮ó��
					dfs(i, j); //���� ���߰�	 �ִ� ��ġ�� dfs ����
				}
			}
		}
		cout << result << endl;
	}
	return 0;
}