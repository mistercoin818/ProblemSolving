#include <bits/stdc++.h>

using namespace std;

int main() {
	string n;
	while (true) {
		cin >> n;
		if (n == "0") {
			break;
		}
		int ll = n.length();
		int l = n.length() / 2;
		bool flag = true;
		for (int i = 0; i < l; ++i) {
			if (n[i] != n[ll - 1 - i]) {
				flag = false;
				break;
			}
		}
		if (flag) {
			printf("yes\n");
		}
		else {
			printf("no\n");
		}
	}
}