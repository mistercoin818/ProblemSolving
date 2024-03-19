#include<iostream>
#include<vector>
using namespace std;

int N;
double before, maxi;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	vector<double> v(N);
	for (int n = 0; n < N; ++n) {
		cin >> v[n];
	}
	before = v[0];
	maxi = v[0];
	for (int i = 0; i < N; ++i) {
		double before = 1;
		for (int j = i; j < N; ++j) {
			before *= v[j];
			if (before > maxi) maxi = before;
		}
	}
	cout << fixed;
	cout.precision(3);
	cout << maxi;
}