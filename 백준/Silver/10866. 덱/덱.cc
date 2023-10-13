#include <iostream>
#include <deque>

using namespace std;

int main() {
	int N;
	cin >> N;
	deque<int> dq;
	for (int i = 0; i < N; ++i) {
		string command;
		cin >> command;
		if (command == "push_front") {
			int X;
			cin >> X;
			dq.push_front(X);
		}
		else if (command == "push_back") {
			int X;
			cin >> X;
			dq.push_back(X);
		}
		else {
			if (dq.empty()) {
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
				if (command == "pop_front") {
					cout << dq.front() << '\n';
					dq.pop_front();
				}
				else if (command == "pop_back") {
					cout << dq.back() << '\n';
					dq.pop_back();
				}
				else if (command == "size") {
					cout << dq.size() << '\n';
				}
				else if (command == "empty") {
					cout << 0 << '\n';
				}
				else if (command == "front") {
					cout << dq.front() << '\n';
				}
				else if (command == "back") {
					cout << dq.back() << '\n';
				}
			}
		}
	}
}