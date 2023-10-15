#include <iostream>

using namespace std;
int n, f[1001];

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n;
	f[1] = 1;
	f[2] = 2;
	if (n == 1 || n == 2) cout << n;
	else {
		for (int i = 3; i <= n; ++i) {
			f[i] = (f[i - 1] + f[i - 2])%10007;
		}
		cout << f[n];
	}
}