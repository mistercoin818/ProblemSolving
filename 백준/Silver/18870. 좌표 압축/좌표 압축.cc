#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N;
vector<pair<int, pair<int, int>>> v;

bool compare(const pair<int, pair<int, int>>& a, const pair<int, pair<int, int>>& b) {
	return a.second.first < b.second.first;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; ++i) {
		int num;
		cin >> num;
		v.push_back({ num, {i, 0} });
	}
	sort(v.begin(), v.end());
	for (int i = 1; i < N; ++i) {
		if (v[i].first == v[i - 1].first) {
			v[i].second.second = v[i - 1].second.second;
		}
		else {
			v[i].second.second = v[i-1].second.second + 1;
		}
	}

	sort(v.begin(), v.end(), compare);
	for (int i = 0; i < N; ++i) {
		cout << v[i].second.second << ' ';
	}
}