#include <iostream>

using namespace std;
const int max_n = 10000;
int arr[max_n + 1];

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);

	int N;
	cin >> N;

	for (int i = 0; i < N; ++i) {
		int num;
		cin >> num;
		++arr[num];
	}
	
	for (int i = 0; i < max_n+1; ++i) {
		for (int j = 0; j < arr[i]; ++j) {
			cout << i << '\n';
		}
	}
}