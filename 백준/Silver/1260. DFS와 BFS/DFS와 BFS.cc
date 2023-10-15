#include <iostream>
#include <string.h>
#include <queue>

using namespace std;
const int max_n = 1001;
int N, M, V;
bool graph[max_n][max_n], visited[max_n];

void dfs(int x) {
	visited[x] = true;
	cout << x << " ";
	for (int i = 1; i <= N; ++i) {
		if (graph[x][i] && !visited[i]) {
			dfs(i);
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N >> M >> V;
	for (int i = 0; i < M; ++i) {
		int a, b;
		cin >> a >> b;
		graph[a][b] = true;
		graph[b][a] = true;
	}
	cout << V << " ";
	visited[V] = true;
	for (int i = 1; i <= N; ++i) {
		if (graph[V][i] && !visited[i]) {
			dfs(i);
		}
	}
	cout << '\n';
	memset(visited, false, sizeof(visited));
	queue<int> q;
	visited[V] = true;
	cout << V << " ";
	q.push(V);
	while (q.size()) {
		int temp = q.front();
		q.pop();
		for (int i = 1; i <= N; ++i) {
			if (graph[temp][i] && !visited[i]) {
				q.push(i);
				visited[i] = true;
				cout << i << " ";
			}
		}
	}
}