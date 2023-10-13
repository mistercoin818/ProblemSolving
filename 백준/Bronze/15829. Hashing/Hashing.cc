#include <iostream>

using namespace std;
const int r = 31;
const int M = 1234567891;

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);

	int L;
	cin >> L;
	string input;
	cin >> input;
	long long sum = 0;
	for (int i = 0; i < L; ++i) {
		int p = 1;
		for (int j = 0; j < i; ++j) {
			p *= r;
			p %= M;
		}
		int temp = input[i] - 96;
		sum += (temp * p) % M;
	}
	cout << sum % M;
}