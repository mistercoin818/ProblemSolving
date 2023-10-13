#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	int N;
	cin >> N;
	vector<pair<int, int>> vec;
	for (int i = 0; i < N; ++i) {
		int y, x;
		cin >> x >> y;
		vec.push_back({ y, x });
	}
	sort(vec.begin(), vec.end());
	for (int i = 0; i < N; ++i) {
		cout << vec[i].second << ' ' << vec[i].first << '\n';
	}
}