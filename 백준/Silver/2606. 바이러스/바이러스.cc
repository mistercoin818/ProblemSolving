#include <iostream>
#include <vector>

using namespace std;
int n, line;
vector<int> arr[101];
bool visited[101];

void dfs(int x) {
	visited[x] = true;
	for (int i = 0; i < arr[x].size(); ++i) {
		if (visited[arr[x][i]]) continue;
		dfs(arr[x][i]);
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n >> line;
	for (int i = 0; i < line; ++i) {
		int a, b;
		cin >> a >> b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	visited[1] = true;
	for (int i = 0; i < arr[1].size(); ++i) {
		dfs(arr[1][i]);
	}
	int cnt = 0;
	for (int i = 1; i <= n; ++i) {
		if (visited[i]) {
			++cnt;
		}
	}
	cout << cnt -1;
}