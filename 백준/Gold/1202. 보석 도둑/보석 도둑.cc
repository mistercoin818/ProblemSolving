#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
int N, K;
vector<pair<int, int>> jewel;
vector<int> bag;


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	for (int i = 0; i < N; ++i) {
		int M, V;
		cin >> M >> V;
		jewel.push_back({ M, V });
	}
	for (int i = 0; i < K; ++i) {
		int C;
		cin >> C;
		bag.push_back(C);
	}
	sort(jewel.begin(), jewel.end());
	sort(bag.begin(), bag.end());

	int index = 0;
	priority_queue<int> pq;
	long long sum = 0;
	for (int i = 0; i < K; ++i) {
		while (index < N && (jewel[index].first <= bag[i])) {
			pq.push(jewel[index++].second);
		}
		if (pq.size()) {
			sum += pq.top();
			pq.pop();
		}
	}
	cout << sum;
}