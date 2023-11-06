#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;
int N, M, paper[500][500], maxi;
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
bool visited[500][500];
void dfs(int y, int x, int n, int total) {
	total += paper[y][x];
	--n;
	if (!(n)) {
		maxi = max(maxi, total);
		return;
	}
	for (int i = 0; i < 4; ++i) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
		if (visited[ny][nx]) continue;
		visited[ny][nx] = true;
		dfs(ny, nx, n, total);
		visited[ny][nx] = false;
	}
}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> paper[i][j];
		}
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			visited[i][j] = true;
			dfs(i, j, 4, 0);
			memset(visited, false, sizeof(visited));
		}
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			vector<pair<int, int>> v;
			for (int k = 0; k < 4; ++k) {
				int ny = i + dy[k];
				int nx = j + dx[k];
				if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
				if (visited[ny][nx]) continue;
				v.push_back({ ny, nx });
			}
			if (v.size() == 4) {
				int mini = 1000, tmpSum = 0;
				for (int k = 0; k < 4; ++k) {
					tmpSum += paper[v[k].first][v[k].second];
					if(paper[v[k].first][v[k].second] < mini){
						mini = paper[v[k].first][v[k].second];
 					}
				}
				maxi = max(maxi, tmpSum - mini + paper[i][j]);
			}
			else if (v.size() == 3) {
				int mini = 1000, tmpSum = 0;
				for (int k = 0; k < 3; ++k) {
					tmpSum += paper[v[k].first][v[k].second];
				}
				maxi = max(maxi, tmpSum + paper[i][j]);
			}
		}
	}
	cout << maxi;
}