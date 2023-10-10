#include <bits/stdc++.h>

using namespace std;
int T;

int maxFive(int N) {
	int ret = 1;
	while (true) {
		int res = 1;
		for (int i = 1; i <= ret; ++i) {
			res *= 5;
		}
		if (N >= res) {
			++ret;
		}
		else {
			break;
		}
	}
	return ret;
}

int main() {
	scanf("%d", &T);
	for (int i = 0; i < T; ++i) {
		int N;
		scanf("%d", &N);
		if (N < 5) {
			printf("%d\n", 0);
		}
		else {
			int cnt = 0;
			int M = maxFive(N);
			for (int i = 1; i <= M; ++i) {
				int five = 1;
				for (int j = 1; j <= i; ++j) {
					five *= 5;
				}
				int temp = N / five;
				cnt += temp;
			}
			printf("%d\n", cnt);
		}
	}
}