#include <iostream>
using namespace std;
#define MAX 101
int N; // 정점의 개수
int map[MAX][MAX]; // 행렬
int visited[MAX][MAX]; // 경로 파악 배열
void dfs(int start, int x) { // start : 시작정점
	map[start][x] = 1;
	visited[start][x] = 1;
	for (int j = 1; j <= N; j++) {
		if (!visited[start][j] && map[x][j])
			dfs(start, j);
	}
}
int main(){
	// 정점의 개수를 입력
	cin >> N;
	// N크기의 행렬에 데이터 입력	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++)	
			cin >> map[i][j];
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++){ // 첫번째 정점부터 확인
			if (!visited[i][j] && map[i][j])
				dfs(i, j); //현재 좌표값 i, j(start, x)
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++)
			cout << map[i][j] << " ";
		cout << endl;
	}
	return 0;
}