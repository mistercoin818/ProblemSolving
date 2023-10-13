#include <iostream>
#include <vector>

using namespace std;

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		int N, M;
		cin >> N >> M;
		vector<int> v;
		for (int j = 0; j < N; ++j) {
			int n;
			cin >> n;
			v.push_back(n);
		}
		if (N == 1) {
			cout << 1 << '\n';
		}
		else {
			int cnt = 0;
			int target = M;
			bool isOut = false;
			while (!isOut) {
				int l = v.size();
				int now = v[0];
				bool flag = true;
				for (int i = 1; i < l; ++i) {
					if (v[i] > now) {
						flag = false;
						break;
					}
				}
				if (!flag) {
					v.erase(v.begin());
					v.push_back(now);
					if (!target) {
						target = v.size()-1;
					}
					else {
						--target;
					}
				}
				else {

					v.erase(v.begin());
					++cnt;
					if (!target) {
						isOut = true;
					}
					else {
						--target;
					}
				}
			}
			cout << cnt << '\n';
		}
	}
}