#include <iostream>
#include <string.h>
using namespace std;
int N, M, board[100][100], tmp[100][100], cnt, cheese;
bool visited[100][100];
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
void dfs(int y, int x) {
	visited[y][x] = true;
	for (int i = 0; i < 4; ++i) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= N || nx >= M || visited[ny][nx]) continue;
		if (board[ny][nx]) ++tmp[ny][nx];
		else dfs(ny, nx);
	}
}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> board[i][j];
			tmp[i][j] = board[i][j];
			if (board[i][j]) ++cheese;
		}
	}
	while (cheese) {
		cheese = 0;
		++cnt;
		dfs(0, 0);
		memset(visited, false, sizeof(visited));
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				if (tmp[i][j] >= 3) tmp[i][j] = 0;
				else if (tmp[i][j] == 2) tmp[i][j] = 1;
				board[i][j] = tmp[i][j];
				if (board[i][j]) {
					++cheese;
				}
			}
		}
	}
	cout << cnt;
}