#include <iostream>
#include <algorithm>

using namespace std;

int N, K, dp[100][100001], res;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	for (int n = 0; n < N; ++n) {
		int walkTime, walkMoney, biTime, biMoney;
		cin >> walkTime >> walkMoney >> biTime >> biMoney;
		if (n) {
			for (int k = 0; k < K; ++k) {
				if (dp[n - 1][k]) {
					if (k + walkTime <= K) dp[n][k + walkTime] = max(dp[n][k + walkTime], dp[n - 1][k] + walkMoney);
					if (k + biTime <= K) dp[n][k + biTime] = max(dp[n][k + biTime], dp[n - 1][k] + biMoney);
				}
			}
		} else {
			dp[0][walkTime] = max(dp[0][walkTime], walkMoney);
			dp[0][biTime] = max(dp[0][biTime], biMoney);
		}
	}
	for (int k = 0; k <= K; ++k) {
		if (dp[N - 1][k]) res = max(res, dp[N - 1][k]);
	}
	cout << res;
}