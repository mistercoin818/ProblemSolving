#include <iostream>
#include <stack>

using namespace std;

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);

	int N;
	cin >> N;
	stack<int> s;
	for (int i = 0; i < N; ++i) {
		string command;
		cin >> command;
		if (command == "push") {
			int X;
			cin >> X;
			s.push(X);
		}
		else {
			if (command == "top") {
				if (s.empty()) {
					cout << -1 << '\n';
				}
				else {
					cout << s.top() << '\n';
				}
			}
			else if (command == "size") {
				cout << s.size() << '\n';
			}
			else if (command == "empty") {
				cout << s.empty() <<'\n';
			}
			else {
				if (s.empty()) {
					cout << -1 << '\n';
				}
				else {
					cout << s.top() << '\n';
					s.pop();
				}
			}
		}
	}
}