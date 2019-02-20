#include <stdio.h>

int n; // ������ �� ����
int map[30][30], visit[30]; // ���� ��İ� �湮 ���θ� ��Ÿ���� �迭

void DFS(int v)
{
	int i;

	visit[v] = 1; // ���� v�� �湮�ߴٰ� ǥ��
	for (i = 1; i <= n; i++)
	{
		// ���� v�� ���� i�� ����Ǿ���, ���� i�� �湮���� �ʾҴٸ�
		if (map[v][i] == 1 && !visit[i])
		{
			printf("%d���� %d�� �̵�\n", v, i);
			// ���� i���� �ٽ� DFS�� �����Ѵ�
			DFS(i);
		}
	}
}

int main()
{
	int start; // ���� ����
	int v1, v2;

	scanf("%d%d", &n, &start);

	while (1)
	{
		scanf("%d%d", &v1, &v2);
		if (v1 == -1 && v2 == -1) 
			break; // -1�� -1�� �ԷµǸ� ���� ���� Ż��
		map[v1][v2] = map[v2][v1] = 1; // ���� v1�� ���� v2�� ����Ǿ��ٰ� ǥ��
	}
	DFS(start); // DFS ����!

	return 0;
}