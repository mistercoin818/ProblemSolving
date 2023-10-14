#include <iostream>
#include <vector>

using namespace std;
int T;
vector<pair<long long , long long>> vec;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> T;
	vec.push_back({ 0, 1 });
	vec.push_back({ 1, 0 });
	for (int i = 2; i <= 40; ++i) {
		long long one = vec[i - 1].first + vec[i - 2].first;
		long long zero = vec[i - 1].second + vec[i - 2].second;
		vec.push_back({ one, zero });
	}
	for (int i = 0; i < T; ++i) {
		int temp;
		cin >> temp;
		cout << vec[temp].second << " " << vec[temp].first << '\n';
	}
}