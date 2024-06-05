#include <iostream>

using namespace std;
long long N, atk, damage, heal, res;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> atk;
	for (int n = 1; n <= N; ++n) {
		int t;
		long long a, h;
		cin >> t >> a >> h;
		if (t == 1) {
			if (atk >= h) continue;
			if (h % atk == 0) damage += a * (h / atk - 1);
			else damage += a * (h / atk);
		}
		else {
			long long temp = damage >= h ? h : damage;
			damage -= temp;
			atk += a;
		}
		res = max(res, damage);
	}
	cout << res + 1;
}