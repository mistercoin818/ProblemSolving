#include <iostream>

using namespace std;
const int max_n = 132;
int N, coloredPaper[max_n][max_n], white = 0, blue = 0;

void DAQ(int y, int x, int n) {
	int temp = coloredPaper[y][x];
	bool flag = false;
	for (int i = y; i < y + n; ++i) {
		for (int j = x; j < x + n; ++j) {
			if (coloredPaper[i][j] != temp) {
				flag = true;
				break;
			}
		}
		if (flag) {
			break;
		}
	}
	if (flag) {
		DAQ(y, x, n / 2);
		DAQ(y, x + n / 2, n / 2);
		DAQ(y + n / 2, x, n / 2);
		DAQ(y + n / 2, x + n / 2, n / 2);
	}
	else {
		if (temp) {
			++blue;
		}
		else {
			++white;
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> coloredPaper[i][j];
		}
	}
	DAQ(0, 0, N);
	cout << white << '\n' << blue;
}