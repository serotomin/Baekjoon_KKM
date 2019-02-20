#include <iostream>
using namespace std;
#define MAX 101
int N; // ������ ����
int map[MAX][MAX]; // ���
int visited[MAX][MAX]; // ��� �ľ� �迭
void dfs(int start, int x) { // start : ��������
	map[start][x] = 1;
	visited[start][x] = 1;
	for (int j = 1; j <= N; j++) {
		if (!visited[start][j] && map[x][j])
			dfs(start, j);
	}
}
int main(){
	// ������ ������ �Է�
	cin >> N;
	// Nũ���� ��Ŀ� ������ �Է�	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++)	
			cin >> map[i][j];
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++){ // ù��° �������� Ȯ��
			if (!visited[i][j] && map[i][j])
				dfs(i, j); //���� ��ǥ�� i, j(start, x)
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++)
			cout << map[i][j] << " ";
		cout << endl;
	}
	return 0;
}