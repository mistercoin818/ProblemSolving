#include <iostream>
#include <cmath>

using namespace std;
int N, r, c;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N >> r >> c;
	int n = (int)pow(2, N);
	int nn = n * n;
	int y = 0, x = 0;
	int cnt = 0;
	while (n) {
		n /= 2;
		nn /= 4;
		if ((r < (y + n)) && (c < (x + n))) {
			continue;
		}
		else if ((r < (y + n)) && (c >= (x + n))) {
			cnt += nn;
			x += n;
		}
		else if ((r >= (y + n)) && (c < (x + n))) {
			cnt += nn * 2;
			y +=n;
		}
		else {
			cnt += nn *3;
			x += n;
			y += n;
		}
	}
	cout << cnt;
}