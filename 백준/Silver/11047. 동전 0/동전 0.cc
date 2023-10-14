#include <iostream>

using namespace std;
int N, K, arr[10];

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	cin >> N >> K;
	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
	}
	int cnt = 0;
	for (int i = N - 1; i >= 0; --i) {
		cnt += K / arr[i];
		K %= arr[i];
	}
	cout << cnt;
}