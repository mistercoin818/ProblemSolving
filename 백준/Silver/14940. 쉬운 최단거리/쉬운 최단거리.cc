#include <iostream>
#include <queue>
#include <tuple>

using namespace std;
const int max_n = 1004;
int n, m, ma[max_n][max_n], x, y, visited[max_n][max_n];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
queue<pair<int, int>> q;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> ma[i][j];
			if (ma[i][j] == 2) {
				y = i;
				x = j;
			}
		}
	}
	q.push({y, x});
	visited[y][x] = 1;
	while (q.size()) {
		tie(y, x) = q.front();
		q.pop();
		for (int i = 0; i < 4; ++i) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || ny >= n || nx < 0 || nx >= m || ma[ny][nx] == 0) continue;
			if (visited[ny][nx]) continue;
			visited[ny][nx] = visited[y][x] + 1;
			q.push({ ny, nx });
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (visited[i][j] > 0) {
				cout << --visited[i][j] << ' ';
			}
			else if (ma[i][j] == 0) {
				cout << 0 << ' ';
			}
			else {
				cout << -1 << ' ';
			}
		}
		cout << '\n';
	}
}