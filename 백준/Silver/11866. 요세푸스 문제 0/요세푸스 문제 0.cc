#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N, K, cnt = 0, i = 0;
	cin >> N >> K;
	vector<int> vec;
	for (int i = 1; i <= N; ++i) {
		vec.push_back(i);
	}
	cout << '<';
	while (vec.size()) {
		i += K - 1;
		int l = vec.size();
		if (i >= l) {
			while (i >= l) {
				i -= l;
			}
		}
		int temp = vec[i];
		vec.erase(vec.begin() + i);
		if (vec.size()) {
			cout << temp << ", ";
		}
		else {
			cout << temp << '>';
		}
	}
}