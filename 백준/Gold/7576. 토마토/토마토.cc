#include <iostream>
#include <queue>
#include <tuple>

using namespace std;
const int max_n = 1000;
int M, N, y, x, box[max_n][max_n], visited[max_n][max_n];
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
queue<pair<int, int>> q;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> M >> N;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> box[i][j];
			if (box[i][j] == 1) {
				q.push({ i, j });
				visited[i][j] = 1;
			}
		}
	}
	while (q.size()) {
		tie(y, x) = q.front(); q.pop();
		for (int i = 0; i < 4; ++i) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || ny >= N || nx < 0 || nx >= M || box[ny][nx] == -1) continue;
			if (visited[ny][nx] == 1) continue;
			if (visited[ny][nx] == 0 || box[ny][nx] == 0) {
				visited[ny][nx] = visited[y][x] + 1;
				box[ny][nx] = 1;
				q.push({ ny, nx });
			}
		}
	}
	bool flag = true;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (box[i][j] == 0) {
				flag = false;
				break;
			}
		}
		if (!flag) {
			break;
		}
	}
	if (!flag) {
		cout << -1;
	}
	else {
		int maxi = 0;
		for(int i = 0; i <N; ++i){
			for (int j = 0; j < M; ++j) {
				if (visited[i][j] > maxi) {
					maxi = visited[i][j];
				}
			}
		}
		cout << maxi - 1;
	}
}