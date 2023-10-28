#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int N, M, a[101], visited[101], mini = 2147483647, ans;
vector<int> v[101];
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int m = 0; m < M; ++m) {
		int A, B;
		cin >> A >> B;
		v[A].push_back(B);
		v[B].push_back(A);
	}
	for (int n = 1; n <= N; ++n) {
		queue<int> q;
		q.push(n);
		int sum = 1;
		visited[n] = 1;
		while (!q.empty()) {
			int f = q.front();
			q.pop();
			int l = v[f].size();
			for (int i = 0; i < l; ++i) {
				if (!visited[v[f][i]]) {
					q.push(v[f][i]);
					visited[v[f][i]] = visited[f] + 1;
					sum += visited[v[f][i]];
				}
			}
		}
		if (sum < mini) {
			mini = sum;
			ans = n;
		}
		memset(visited, 0, sizeof(visited));
	}
	cout << ans;
}