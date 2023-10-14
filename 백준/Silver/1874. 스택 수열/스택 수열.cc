#include <iostream>
#include <vector>
#include <stack>

using namespace std;
int n;
vector<int> v;
vector<char> order;
stack<int> s;

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
	bool flag = true;
	int last_max = 0;
	for (int i = 0; i < n; ++i) {
		if (s.empty()) {
			for (int j = last_max + 1; j <= v[i]; ++j) {
				s.push(j);
				order.push_back('+');
				last_max = j;
			}
			s.pop();
			order.push_back('-');
		}
		else {
			if (v[i] > s.top()) {
				for (int j = last_max + 1; j <= v[i]; ++j) {
					s.push(j);
					order.push_back('+');
					last_max = j;
				}
				s.pop();
				order.push_back('-');
			}
			else if(v[i] == s.top()) {
				s.pop();
				order.push_back('-');
			}
			else {
				flag = false;
				break;
			}
		}
	}
	if (flag) {
		for (auto sign : order) {
			cout << sign << '\n';
		}
	}
	else {
		cout << "NO";
	}
}