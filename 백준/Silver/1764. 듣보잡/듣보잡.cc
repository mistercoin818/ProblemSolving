#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
int N, M;
vector<string> hear;
vector<string> see;
set<string> hashmap[26];
vector<string> ans;

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		string temp;
		cin >> temp;
		hear.push_back(temp);
	}
	sort(hear.begin(), hear.end());
	for (int i = 0; i < N; ++i) {
		int temp = hear[i][0] - 'a';
		hashmap[temp].insert(hear[i]);
	}
	for (int i = 0; i < M; ++i) {
		string temp;
		cin >> temp;
		see.push_back(temp);
	}
	sort(see.begin(), see.end());
	int res = 0;
	for (int i = 0; i < M; ++i) {
		int index = see[i][0] - 'a';
		if (hashmap[index].size()) {
			set<string>::iterator iter;
			iter = hashmap[index].find(see[i]);
			if (iter != hashmap[index].end()) {
				++res;
				ans.push_back(see[i]);
			}
		}
	}
	cout << res << '\n';
	for (int i = 0; i < res; ++i) {
		cout << ans[i] << '\n';
	}
}