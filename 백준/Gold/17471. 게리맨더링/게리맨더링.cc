#include<iostream>
#include<cstring>
#include<algorithm>
#include<climits>
using namespace std;

int N, population[10], boj[10][10], res = -1, mini = INT_MAX;
bool check[10], visited[10];


void dfs(int x) {
	visited[x] = true;
	for (int i = 0; i < N; ++i) {
		if (boj[x][i] && !visited[i] && (check[x] == check[i])) dfs(i);
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int n = 0; n < N; ++n) {
		cin >> population[n];
	}
	for (int n = 0; n < N; ++n) {
		int adjNum;
		cin >> adjNum;
		for (int a = 0; a < adjNum; ++a) {
			int m;
			cin >> m;
			boj[n][m - 1] = 1;
			boj[m - 1][n] = 1;
		}
	}
	for (int i = 1; i < (1 << N) - 1; ++i) {
		int start = -1, anotherStart = -1;
		for (int j = 0; j < N; ++j) {
			if (i & (1 << j)) {
				check[N - 1 - j] = true;
				if (start < 0) start = N - 1 - j;
			}
			else {
				if (anotherStart < 0) anotherStart = N - 1 - j;
			}
		}
		dfs(start);
		bool flag = true;
		for (int index = 0; index < N; ++index) {
			if (check[index] != visited[index]) {
				flag = false;
				break;
			}
		}
		bool realFlag = true;
		if (flag) {
			memset(visited, false, sizeof(visited));
			dfs(anotherStart);
			for (int index = 0; index < N; ++index) {
				if (check[index] == visited[index]) {
					realFlag = false;
					break;
				}
			}
		}

		if (flag && realFlag) {
			int a = 0, b = 0;
			for (int index = 0; index < N; ++index) {
				if (check[index]) a += population[index];
				else b += population[index];
			}
			mini = min(mini, abs(a - b));
		}
		memset(visited, false, sizeof(visited));
		memset(check, false, sizeof(check));
	}
	if (mini != INT_MAX) res = mini;
	cout << res;
}