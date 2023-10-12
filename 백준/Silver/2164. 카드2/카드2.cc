#include <iostream>
#include <queue>

using namespace std;

int main() {
	int N;
	cin >> N;
	queue<int> q;
	for (int i = 1; i <=N; ++i) {
		q.push(i);
	}
	int cnt = 1;
	int last = 0;
	int temp = 0;
	while (q.size()) {
		if (cnt % 2) {
			last = q.front();
			q.pop();
		}
		else {
			temp = q.front();
			q.pop();
			q.push(temp);
			last = q.front();
		}
		++cnt;
	}
	cout << last;
}