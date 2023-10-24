#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N;
vector<pair<int, int>> v;
vector<pair<int, int>> temp;

bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	return a.second < b.second;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; ++i) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a, b });
	}
	sort(v.begin(), v.end(), compare);
	int maxi = 0;
	temp.push_back(v[0]);
	for (int i = 1; i < N; ++i) {
		if (v[i].first >= temp.back().second) {
			temp.push_back(v[i]);
		}
	}
	cout << temp.size();
}