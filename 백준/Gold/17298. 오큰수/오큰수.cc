#include <iostream>
#include <stack>
#include <string.h>
using namespace std;
int N, arr[1000000];
stack<pair<int, int>> s;
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	memset(arr, -1, sizeof(arr));
	int a, i = 0;
	cin >> a;
	s.push({ a, i });
	for (int i = 1; i < N; ++i) {
		int b;
		cin >> b;
		while (!s.empty() && s.top().first < b) {
			arr[s.top().second] = b;
			s.pop();
		}
		s.push({ b, i });
	}
	for (int i = 0; i < N; ++i) {
		cout << arr[i] << ' ';
	}
}