#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
#include <cstdlib>
#include <cstring>
using namespace std;
int N, L, R, land[50][50], sum, n, connected[50][50], mode;
bool visited[50][50];
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
vector<pair<int, int>> v;
void dfs(int y, int x, int m) {
	visited[y][x] = true;
	v.push_back({ y, x });
	sum += land[y][x];
	++n;
	for (int i = 0; i < 4; ++i) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
		if (visited[ny][nx]) continue;
		if (connected[ny][nx] == m) dfs(ny, nx, m);
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> L >> R;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> land[i][j];
		}
	}
	bool flag;
	int cnt = 0;
	do {
		flag = false;
		++cnt;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				if (!connected[i][j]) {
					++mode;
					bool mode_used = false;
					queue<pair<int, int>> q;
					q.push({ i, j });
					while (!q.empty()) {
						int y, x;
						tie(y, x) = q.front(); q.pop();
						for (int k = 0; k < 4; ++k) {
							int ny = y + dy[k];
							int nx = x + dx[k];
							if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
							if (connected[ny][nx]) continue;
							int diff = abs(land[ny][nx] - land[y][x]);
							if ((L <= diff) && (diff <= R)) {
								connected[y][x] = mode;
								connected[ny][nx] = mode;
								flag = true;
								q.push({ ny, nx });
							}
						}
					}
				}
			}
		}
		if (flag) {
			for (int i = 0; i < N; ++i) {
				for (int j = 0; j < N; ++j) {
					if (connected[i][j] && !visited[i][j]) {
						dfs(i, j, connected[i][j]);
						int changed = sum / n;
						int l = v.size();
						for (int k = 0; k < l; ++k) {
							land[v[k].first][v[k].second] = changed;
						}
						sum = 0;
						n = 0;
						v.clear();
					}
				}
			}
			memset(visited, false, sizeof(visited));
			memset(connected, 0, sizeof(connected));
		}
		/*cout << "-----------------------------\n";
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				cout << land[i][j] << ' ';
			}
			cout << '\n';
		}
		cout << "-----------------------------\n";*/
	} while (flag);
	cout << cnt - 1;
}