#include <bits/stdc++.h>

using namespace std;
const int max_n = 104;
int N, cnt = 0, cntt = 0;
char painting[max_n][max_n], painting2[max_n][max_n];
bool visited[max_n][max_n], visited2[max_n][max_n];
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

void dfs(int y, int x, char color) {
	visited[y][x] = true;
	for (int i = 0; i < 4; ++i) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny > N || nx > N) continue;
		if (!visited[ny][nx] && painting[ny][nx] == color) {
			dfs(ny, nx, color);
		}
	}
	return;
}

void dfs2(int y, int x, char color) {
	visited2[y][x] = true;
	for (int i = 0; i < 4; ++i) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny > N || nx > N) continue;
		if (!visited2[ny][nx] && painting2[ny][nx] == color) {
			dfs2(ny, nx, color);
		}
	}
	return;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> painting[i][j];
			if (painting[i][j] == 'G') {
				painting2[i][j] = 'R';
			}
			else {
				painting2[i][j] = painting[i][j];
			}
		}
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (!visited[i][j]) {
				dfs(i, j, painting[i][j]);
				++cnt;
			}
		}
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (!visited2[i][j]) {
				dfs2(i, j, painting2[i][j]);
				++cntt;
			}
		}
	}
	cout << cnt << " " << cntt;
}