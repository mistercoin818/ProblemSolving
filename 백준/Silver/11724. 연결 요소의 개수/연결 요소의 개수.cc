#include <iostream>
#include <vector>

using namespace std;
int N, M, cnt = 0;
bool visited[1001];
vector<int> arr[1001];

void dfs(int x) {
	visited[x] = true;
	for (int i = 0; i < arr[x].size(); ++i) {
		if (!visited[arr[x][i]]) {
			dfs(arr[x][i]);
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 0; i < M; ++i) {
		int a, b;
		cin >> a >> b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	
	for (int i = 1; i <= N; ++i) {
		if (!visited[i]) {
			dfs(i);
			++cnt;
		}
	}
	cout << cnt;
}