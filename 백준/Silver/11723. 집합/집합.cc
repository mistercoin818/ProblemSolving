#include <iostream>
#include <set>

using namespace std;
int M;

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	cin >> M;
	set<int> s;
	for (int i = 0; i < M; ++i) {
		string command;
		cin >> command;
		
		if (command == "all") {
			for (int i = 1; i <= 20; ++i) {
				s.insert(i);
			}
		}
		else if (command == "empty") {
			s.erase(s.begin(), s.end());
		}
		else {
			int x;
			cin >> x;
			if (command == "add") {
				s.insert(x);
			}
			else if (command == "remove") {
				s.erase(x);
			}
			else if (command == "check") {
				cout << s.count(x) << '\n';
			}
			else if (command == "toggle") {
				if (s.count(x)) {
					s.erase(x);
				}
				else {
					s.insert(x);
				}
			}
		}
	}
}