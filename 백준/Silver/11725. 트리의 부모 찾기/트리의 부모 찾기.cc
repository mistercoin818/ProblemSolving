#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
int N, arr[1000001];
queue<pair<int, int>> q;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	vector<vector<int>> tree(N+1);
	for (int i = 0; i < N-1; ++i) {
		int a, b;
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	for (int i = 0; i < tree[1].size(); ++i) {
		q.push({ 1, tree[1][i] });
	}
	while (!q.empty()) {
		int parent, child;
		tie(parent, child) = q.front(); q.pop();
		if (!arr[child]) arr[child] = parent;
		if (!tree[child].empty()) {
			for (int i = 0; i < tree[child].size(); ++i) {
				if (tree[child][i] == parent) continue;
				q.push({ child, tree[child][i] });
			}
		}
	}
	for (int i = 2; i <= N; ++i) {
		cout << arr[i] << '\n';
	}
}