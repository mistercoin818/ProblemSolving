#include <bits/stdc++.h>

using namespace std;
int T;

int main() {
	cin >> T;
	for (int i = 0; i < T; ++i) {
		string line;
		cin >> line;
		int l = line.length();
		stack<int> st;
		bool flag = true;
		for (int j = 0; j < l; ++j) {
			if (line[j] == '(') {
				st.push(j);
			}
			else {
				if (st.empty()) {
					flag = false;
					break;
				}
				st.pop();
			}
		}
		if (flag && st.empty()) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}
}