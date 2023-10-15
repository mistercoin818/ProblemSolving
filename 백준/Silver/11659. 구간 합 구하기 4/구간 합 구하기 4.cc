#include <iostream>

using namespace std;
int N, M;
int psum[100001];

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 1; i <= N; ++i) {
		int n;
		cin >> n;
		psum[i] = psum[i - 1] + n;
	}
	for (int i = 0; i < M; ++i) {
		int a, b;
		cin >> a >> b;
		cout << psum[b] - psum[a - 1] << '\n';
	}
}