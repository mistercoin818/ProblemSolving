#include <iostream>

using namespace std;
int T, arr[11];

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> T;
	arr[0] = 1;
	arr[1] = 2;
	arr[2] = 4;
	for (int i = 3; i < 11; ++i) {
		arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
	}
	while (T) {
		int n;
		cin >> n;
		cout << arr[n - 1] << '\n';
		--T;
	}
}