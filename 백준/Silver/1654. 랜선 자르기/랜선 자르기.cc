#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	
	int K, N;
	cin >> K >> N;
	vector<int> vec;
	for (int i = 0; i < K; ++i) {
		int len;
		cin >> len;
		vec.push_back(len);
	}
	sort(vec.begin(), vec.end());
	long long low = 1;
	long long high = vec.back();
	long long mid = 0;

	while (low <= high) {
		long long sum = 0;
		mid = low + (high - low) / 2;
		for (int i = 0; i < K; ++i) {
			sum += vec[i] / mid;
		}
		if (sum >= N) {
			low = mid + 1;
		}
		else if (sum < N) {
			high = mid - 1;
		}
	}

	cout << high << '\n';
}