#include <bits/stdc++.h>

using namespace std;
vector<pair<pair<int, int>, string>> vec;

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		int age;
		string line;
		cin >> age >> line;
		vec.push_back({ { age, i }, line });
	}
	sort(vec.begin(), vec.end());
	for (auto a : vec) {
		cout << a.first.first << " " << a.second << '\n';
	}
 }