#include <iostream>
#include <stack>

using namespace std;

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	int K;
	cin >> K;
	stack<int> s;
	for (int i = 0; i < K; ++i) {
		int n;
		cin >> n;
		if (!n) {
			s.pop();
		}
		else {
			s.push(n);
		}
	}
	int l = s.size();
	int sum = 0;
	for (int i = 0; i < l; ++i) {
		sum += s.top();
		s.pop();
	}
	cout << sum;
}