#include <iostream>
#include <queue>
#include <algorithm>
#include <tuple>
#include <string.h>
using namespace std;
char ma[50][50];
int visited[50][50], N, M, result, y, x;
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> ma[i][j];
		}
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			int tmp = 0;
			if (ma[i][j] == 'L') {
				queue<pair<int, int>> q;
				q.push({ i, j });
				visited[i][j] = 1;
				while (!q.empty()) {
					tie(y, x) = q.front(); q.pop();
					for (int k = 0; k < 4; ++k) {
						int ny = y + dy[k];
						int nx = x + dx[k];
						if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
						if (ma[ny][nx] == 'W') continue;
						if (visited[ny][nx]) continue;
						visited[ny][nx] = visited[y][x] + 1;
						tmp = max(tmp, visited[ny][nx]);
						q.push({ ny, nx });
					}
				}
			}
			result = max(result, tmp - 1);
			memset(visited, 0, sizeof(visited));
		}
	}
	cout << result;
}