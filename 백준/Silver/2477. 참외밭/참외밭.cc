#include <iostream>
#include <vector>

using namespace std;

int K, d, l, index = 1;
vector<pair<int, int>> v;

int main() {
	cin >> K;
	for (int i = 0; i < 6; ++i) {
		cin >> d >> l;
		v.push_back({ d, l });
	}
	while (true) {
		if ((v[(index - 1) % 6].first == v[(index + 1) % 6].first) && (v[(index) % 6].first == v[(index + 2) % 6].first)) {
			break;
		}
		else {
			++index;
		}
	}
	cout << (v[(index + 3) % 6].second * v[(index + 4) % 6].second - v[index % 6].second * v[(index + 1) % 6].second)*K;
}
