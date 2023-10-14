#include <iostream>
#include <stdlib.h>

using namespace std;
const int max_n = 504;
int N, M, B, earth[max_n][max_n], copy[max_n][max_n];

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	cin >> N >> M >> B;
	int maxi = 0, mini = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> earth[i][j];
			if (maxi < earth[i][j]) {
				maxi = earth[i][j];
			}
			if (mini > earth[i][j]) {
				mini = earth[i][j];
			}
		}
	}
	int time = 2147483647;
	int height = 0;
	int flag = true;
	int numOfBlocks = B;
	for (int st = mini; st <= maxi; ++st) {
		int sum = 0;
		numOfBlocks = B;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				int gap = abs(earth[i][j] - st);
				if (earth[i][j] > st) {
					sum += 2 * gap;
					numOfBlocks += gap;
				}
				else if (earth[i][j] < st) {
					sum += gap;
					numOfBlocks -= gap;
				}
			}
		}
		if (numOfBlocks < 0) {
			flag = false;
		}
		if (flag) {
			if (time > sum) {
				time = sum;
				height = st;
			}
			else if (time == sum) {
				if (height < st) {
					height = st;
				}
			}
			else {
				continue;
			}
		}
		else {
			break;
		}
	}
	cout << time << " " << height;
}