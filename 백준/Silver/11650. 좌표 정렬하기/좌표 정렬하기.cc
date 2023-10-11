#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	int N;
	cin >> N;
	vector<pair<int, int>> dots;
	for (int i = 0; i < N; ++i) {
		int x, y;
		cin >> x >> y;
		dots.push_back({ x, y });
	}
	sort(dots.begin(), dots.end());
	for (auto dot : dots) {
		cout << dot.first << ' ' << dot.second << '\n';
	}
}