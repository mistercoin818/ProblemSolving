#include <iostream>
#include <queue>
#include <iomanip>

using namespace std;
int N;
priority_queue<double, vector<double>, greater<double>> pq;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; ++i) {
		double grade;
		cin >> grade;
		pq.push(grade);
	}
	cout << fixed;
	cout.precision(3);
	for (int i = 0; i < 7; ++i) {
		cout << pq.top() << '\n';
		pq.pop();
	}
}