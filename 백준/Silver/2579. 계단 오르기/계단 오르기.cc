#include <iostream>
#include <vector>

using namespace std;
int n, stairs[301];
vector<pair<int, int>> dp[301];

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> stairs[i];
	}

	dp[1].push_back({ stairs[1], 1});
	dp[2].push_back({ stairs[2], 1 });
	dp[2].push_back({ stairs[1] + stairs[2], 2 });
	for (int i = 3; i <= n; ++i) {
		int max1 = 0;
		for (int j = 0; j < dp[i - 2].size(); ++j) {
			if (dp[i - 2][j].first > max1) {
				max1 = dp[i - 2][j].first;
			}
		}
		dp[i].push_back({ max1+stairs[i], 1});
		for (int j = 0; j < dp[i - 1].size(); ++j) {
			if (dp[i - 1][j].second < 2) {
				dp[i].push_back({ dp[i - 1][j].first + stairs[i], ++dp[i - 1][j].second});
			}
		}
	}
	
	if (n == 1) {
		cout << stairs[1];
	}
	else if (n == 2) {
		cout << stairs[1] + stairs[2];
	}
	else {
		int max = 0;
		for (int i = 0; i < dp[n].size(); ++i) {
			if (dp[n][i].first > max) {
				max = dp[n][i].first;
			}
		}
		cout << max;
	}
}