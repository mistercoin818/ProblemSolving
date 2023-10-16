#include <iostream>
#include <queue>

using namespace std;
int N, X;
priority_queue<int, vector<int>, greater<int>> q;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> X;
		if (q.empty() && !X) {
			cout << 0 << '\n';
		}
		else if (!X) {
			cout << q.top() << '\n';
			q.pop();
		}
		else {
			q.push(X);
		}
	}
}