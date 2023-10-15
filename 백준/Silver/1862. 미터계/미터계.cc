#include <iostream>
#include <string>

using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	string s = to_string(n);
	int l = s.length();
	int sum = 0;
	for (int i = 0; i < l; ++i) {
		if (s[i] > '4') {
			--s[i];
		}
	}
	int newN = stoi(s);
	for (int i = 0; i < l; ++i) {
		int temp = newN % 10;
		int mul = 1;
		for (int j = 0; j < i; ++j) {
			mul *= 9;
		}
		sum += temp * mul;
		newN /= 10;
	}
	cout << sum;
}