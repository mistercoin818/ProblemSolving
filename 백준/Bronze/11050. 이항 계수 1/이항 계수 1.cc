#include <bits/stdc++.h>

using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	if (K == 0) {
		printf("%d", 1);
	}
	else if (K == 1) {
		printf("%d", N);
	}
	else {
		int a = 1, b = 1;
		for (int i = 1; i <= K; ++i) {
			a *= N--;
		}
		int t = K;
		for (int i = 1; i <= K; ++i) {
			b *= t--;
		}
		printf("%d", a / b);
	}
}