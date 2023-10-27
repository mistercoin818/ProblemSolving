#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;
int N, chess[16][16], cnt;
vector<pair<int, int>> queenSet;

bool isPossible(int y, int x) {
	int l = queenSet.size();
	for (int i = 0; i < l; ++i) {
		if (y == queenSet[i].first || x == queenSet[i].second) return false;
		if (abs(y - queenSet[i].first) == abs(x - queenSet[i].second))return false;
	}
	return true;
}

void backtracking(int y) {
	if (y == N) {
		++cnt;
		return;
	}

	for (int x = 0; x < N; ++x) {
		if (isPossible(y, x)) {
			queenSet.push_back({ y, x });
			backtracking(y + 1);
			queenSet.erase(queenSet.end() - 1);
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	backtracking(0);
	cout << cnt;
}