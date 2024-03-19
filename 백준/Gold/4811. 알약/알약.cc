#include<iostream>
#include<cstring>
using namespace std;

int T, N;
long long dp[31][31];

long long yeah(int y, int x) {
	if (dp[y][x]) return dp[y][x];
	if (x == 0) {
		dp[y][x] = yeah(y, x + 1);
	}
	else {
		dp[y][x] = yeah(y + 1, x - 1) + yeah(y, x + 1);
	}
	return dp[y][x];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	while (true) {
		cin >> N;
		if (!N) break;
		for (int i = 0; i <= N; ++i) {
			dp[i][N - i] = 1;
		}
		cout << yeah(0, 0) << '\n';
		memset(dp, 0, sizeof(dp));
	}
	return 0;
}