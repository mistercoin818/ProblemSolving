#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, arr[1001], psum[1001];
vector<int> v;

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	cin >> N;
	for (int i = 0; i < N; ++i) {
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end());
	for (int i = 1; i <= N; ++i) {
		arr[i] = arr[i - 1] + v[i - 1];
		psum[i] = psum[i - 1] + arr[i];
	}
	cout << psum[N];
}