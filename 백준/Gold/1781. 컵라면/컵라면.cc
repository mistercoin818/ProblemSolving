#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

int N, sum;
pair<int, int> a[200000];
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; ++i) {
		int d, c;
		cin >> d >> c;
		a[i] = { d, c };
	}
	sort(a, a + N);
	for (int i = 0; i < N; ++i) {
		int d = a[i].first;
		pq.push(a[i].second);
		while (d < pq.size()) pq.pop();
	}
	while (!pq.empty()) {
		sum += pq.top();
		pq.pop();
	}
	cout << sum;
}