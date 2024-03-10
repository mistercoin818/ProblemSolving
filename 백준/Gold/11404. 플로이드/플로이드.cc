#include<iostream>
#include<algorithm>
using namespace std;

const int INF = 987654321;
int n, m, city[101][101];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	fill(&city[0][0], &city[100][101], INF);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		city[i][i] = 0;
	}
	for (int i = 0; i < m; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		if (city[a][b] != INF && c >= city[a][b]) continue;
		city[a][b] = c;
	}
	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (city[i][j] > city[i][k] + city[k][j]) {
					city[i][j] = city[i][k] + city[k][j];
				}
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (city[i][j] == INF) city[i][j] = 0;
			cout << city[i][j] << ' ';
		}
		cout << '\n';
	}
}