#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, M, maxi;
vector<int> v;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		int a;
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	int s = v.size();
	int l = 0, r = v[s - 1] - 1;
	long long sum;
	while (l <= r) {
		int mid = (l + r) / 2;
		sum = 0;
		for (int i = 0; i < s; ++i) {
			if (v[i] > mid) sum += v[i] - mid;
		}
		if (sum >= M) l = mid + 1;
		else r = mid - 1;
	}
	cout << r;
}