#include <iostream>

using namespace std;
long long N, M, a, K;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N >> M >> a >> K;
	long long maxi = 0, mini = 0;
	if ((a - K) >= (N - 1)) {
		maxi = N;
	}
	else {
		maxi = a - K + 1;
	}
	if ((a - K) % M) {
		mini = (a - K) / M + 2;
	}
	else {
		mini = (a - K) / M + 1;
	}
	cout << maxi << " " << mini;
}