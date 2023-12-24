#include<iostream>
#include<queue>
#include<cstdlib>
#include<vector>
using namespace std;
int N, K;
vector<pair<int, int>> check(400001);
queue<int> q;
void goBack(int n) {
	if (n == N) {
		cout << N << ' ';
		return;
	}
	goBack(check[n + 200000].second);
	cout << n << ' ';
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	if (N == K) {
		cout << 0 << '\n' << N;
		return 0;
	}
	q.push(N);
	check[N + 200000].second = N;
	while (!q.empty()) {
		int pos = q.front(); q.pop();
		int cnt = check[pos + 200000].first;
		int before = check[pos + 200000].second;
		if (pos - 1 == K || pos + 1 == K  || pos * 2 == K) {
			cout << cnt + 1 << '\n';
			goBack(pos);
			cout << K;
			break;
		}
		else {
			if (pos - 1 >= -199999 && pos - 1 != N && !check[pos + 199999].first) {
				check[pos + 199999].first = cnt + 1;
				check[pos + 199999].second = pos;
				q.push(pos - 1);
			}
			if (pos + 1 <= 200000 && pos + 1 != N && !check[pos + 200001].first) {
				check[pos + 200001].first = cnt + 1;
				check[pos + 200001].second = pos;
				q.push(pos + 1);
			}
			if (abs(pos * 2) <= 200000 && pos * 2 != N && !check[pos * 2 + 200000].first) {
				check[pos * 2 + 200000].first = cnt + 1;
				check[pos * 2 + 200000].second = pos;
				q.push(pos * 2);
			}
		}
	}
}