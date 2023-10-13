#include <iostream>

using namespace std;

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	int N;
	cin >> N;
	int res = 0;
	int k = 5;
	while (k <= N) {
		res += N / k;
		k *= 5;
	}
	cout << res;
}
