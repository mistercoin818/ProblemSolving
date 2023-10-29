#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int N, G[100][100], ans[100][100];
bool visited[100];
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> G[i][j];
			ans[i][j] = G[i][j];
		}
	}
	for (int i = 0; i < N; ++i) {
		queue<int> q;
		for (int j = 0; j < N; ++j) {
			if (G[i][j]) {
				q.push(j);
				ans[i][j] = 1;
				visited[j] = true;
			}
		}
		while (!q.empty()) {
			int a = q.front();
			q.pop();
			for (int k = 0; k < N; ++k) {
				if (G[a][k] && !visited[k]) {
					q.push(k);
					ans[i][k] = 1;
					visited[k] = true;
				}
			}
		}
		memset(visited, false, sizeof(visited));
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cout << ans[i][j] << ' ';
		}
		cout << '\n';
	}
}