#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
const int max_n = 8001;
int arr[max_n] = { 0, };
vector<int> vec;

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	int N;
	cin >> N;
	double sum = 0;
	int maximum, minimum;
	for (int i = 0; i < N; ++i) {
		int num;
		cin >> num;
		++arr[num + 4000];
		vec.push_back(num);
		sum += num;
		if (i) {
			if (num > maximum) {
				maximum = num;
			}
			if (num < minimum) {
				minimum = num;
			}
		}
		else {
			maximum = num;
			minimum = num;
		}
	}

	sort(vec.begin(), vec.end());
	int am = round(sum / N);
	if (am == -0) {
		am = 0;
	}
	cout << am << '\n';
	cout << vec[N / 2] << '\n';
	vector<int> index;
	int cnt = 0;
	for (int i = 0; i < max_n; ++i) {
		if (!arr[i]) {
			continue;
		}
		if (cnt < arr[i]) {
			cnt = arr[i];
		}
	}

	for (int i = 0; i < max_n; ++i) {
		if (cnt == arr[i]) {
			index.push_back(i);
		}
	}
	if (index.size() == 1) {
		cout << index[0]-4000 << '\n';
	}
	else {
		cout << index[1]-4000 << '\n';
	}
	cout << maximum - minimum;
}