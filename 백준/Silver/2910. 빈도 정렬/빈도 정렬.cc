#include <bits/stdc++.h>

using namespace std;
int N, C;

struct info {
	int cnt, index;
};

multimap<int, info> m;

int main() {
	scanf("%d %d", &N, &C);
	for (int i = 0; i < N; ++i) {
		int temp;
		scanf("%d", &temp);
		map<int, info>::iterator it = m.find(temp);
		if (it != m.end()) {
			it->second.cnt++;
		}
		else {
			m.insert({ temp, {1, i} });
		}
	}
	vector<pair<int, info>> vec(m.begin(), m.end());

	sort(vec.begin(), vec.end(), [](const pair<int, info>& a, const pair<int, info>& b) {
		if (a.second.cnt != b.second.cnt) {
			return a.second.cnt > b.second.cnt;
		}
		else {
			return a.second.index < b.second.index;
		}
		});

	for (const auto& pair : vec) {
		for (int i = 0; i < pair.second.cnt; ++i) {
			printf("%d ", pair.first);
		}
	}
}