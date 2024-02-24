#include<iostream>
#include<stack>
#include<algorithm>
#include<cstring>
using namespace std;

const int hihi = 200001;
int n, maxi, indexx[200000], last_start = hihi, last_end = hihi;
string str;
stack<int> s;
bool flag = false;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> str;
	memset(indexx, -1, sizeof(indexx));
	for (int i = 0; i < n; ++i) {
		if (str[i] == '(') {
			s.push(i);
		}
		else {
			if (!s.empty()) {
				flag = true;
				indexx[s.top()] = i;
				s.pop();
			}
		}
	}

	int i = 0;
	while (i < n) {
		if (indexx[i] >= 0) {
			if (last_start == hihi) {
				last_start = i;
				last_end = indexx[i];
				i = indexx[i] + 1;
				maxi = max(last_end - last_start + 1, maxi);
			}
			else if (last_end + 1 == i) {
				last_end = indexx[i];
				i = indexx[i] + 1;
				maxi = max(last_end - last_start + 1, maxi);
			}
		}
		else {
			++i;
			maxi = max(last_end - last_start + 1, maxi);
			last_start = hihi;
			last_end = hihi;
		}
	}
	if (flag) cout << maxi;
	else cout << 0;
}