#include <bits/stdc++.h>

using namespace std;
const int max_n = 104;
int H, W;
char a[max_n][max_n];
int expected[max_n][max_n];

int main() {
	scanf("%d %d", &H, &W);

	for (int i = 0; i < H; ++i) {
		int temp = 0;
		bool flag = false;
		for (int j = 0; j < W; ++j) {
			cin >> a[i][j];
			if (a[i][j] == 'c') {
				expected[i][j] = 0;
				temp = j;
				flag = true;
			}
			else {
				if (flag) {
					expected[i][j] = j - temp;
				}
				else {
					expected[i][j] = -1;
				}
			}
		}
		if (!flag) {
			for (int j = 0; j < W; ++j) {
				expected[i][j] = -1;
			}
		}
	}

	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			printf("%d ", expected[i][j]);
		}
		printf("\n");
	}
}