#include <iostream>
#include <queue>

using namespace std;

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);

	int N;
	cin >> N;
	queue<int> q;
	for (int i = 0; i < N; ++i) {
		string command;
		cin >> command;
		
		if (command == "push") {
			int X;
			cin >> X;
			q.push(X);
		}
		else {
			if (q.empty()) {
				if (command == "size") {
					cout << 0 << '\n';
				}
				else if (command == "empty") {
					cout << 1 << '\n';
				}
				else {
					cout << -1 << '\n';
				}
			}
			else {
				if (command == "pop") {
					cout << q.front() << '\n';
					q.pop();
				}
				else if (command == "size") {
					cout << q.size() << '\n';
				}
				else if (command == "empty") {
					cout << 0 << '\n';
				}
				else if (command == "front") {
					cout << q.front() << '\n';
				}
				else {
					cout << q.back() << '\n';
				}
			}
		}
	}
}