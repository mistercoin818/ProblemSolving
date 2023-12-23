#include<iostream>
#include<queue>
#include<cstdlib>
#include<vector>
using namespace std;
int N, K, res, res_cnt;
// 최단 회수 & 최단 회수까지 오게 되는 가지수
vector<pair<int, int>> check(400001);
queue<int> q;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	if (N == K) {
		cout << 0 << '\n' << 1;
		return 0;
	}
	q.push(N);
	check[N + 200000].second = 1;
	while (!q.empty()) {
		int pos = q.front(); q.pop();
		int cnt = check[pos + 200000].first;
		int howMany = check[pos + 200000].second;
		if (pos == K) {
			res = cnt;
			res_cnt = howMany;
			break;
		}
		
		if (abs(pos * 2) <= 200000 && pos * 2 != N) {
			if (!check[pos * 2 + 200000].first) {
				check[pos * 2 + 200000].first = cnt + 1;
				check[pos * 2 + 200000].second = howMany;
				q.push(pos * 2);
			}
			else if (check[pos * 2 + 200000].first == cnt + 1) check[pos * 2 + 200000].second += howMany;
			
		}
		if (pos + 1 <= 200000 && pos + 1 != N) {
			if (!check[pos + 200001].first) {
				check[pos + 200001].first = cnt + 1;
				check[pos + 200001].second = howMany;
				q.push(pos + 1);
			}
			else if (check[pos + 200001].first == cnt + 1) check[pos + 200001].second += howMany;

		}
		if (pos - 1 >= -200000 && pos - 1 != N) {
			if (!check[pos + 199999].first) {
				check[pos + 199999].first = cnt + 1;
				check[pos + 199999].second = howMany;
				q.push(pos - 1);
			}
			else if (check[pos + 199999].first == cnt + 1) check[pos + 199999].second += howMany;

		}
	}
	cout << res << '\n' << res_cnt;
}