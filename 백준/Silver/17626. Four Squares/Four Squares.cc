#include <iostream>
#include <cmath>

using namespace std;
int n;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n;
	int root = (int)sqrt(n);
	if (n == root * root) {
		cout << 1;
	}
	else {
		bool twoPossible = false;
		for (int i = root; i >= 1; --i) {
			int first_rest = n - i * i;
			int first_root = (int)sqrt(first_rest);
			if (first_root * first_root == first_rest) {
				twoPossible = true;
				break;
			}
		}
		if (twoPossible) {
			cout << 2;
		}
		else {
			bool threePossible = false;
			for (int i = root; i >= 1; --i) {
				int first_rest = n - i * i;
				int first_root = (int)sqrt(first_rest);
				for (int j = first_root; j >= 1; --j) {
					int second_rest = first_rest - j * j;
					int second_root = (int)sqrt(second_rest);
					if (second_root * second_root == second_rest) {
						threePossible = true;
						break;
					}
				}
				if (threePossible) {
					break;
				}
			}
			if (threePossible) {
				cout << 3;
			}
			else {
				cout << 4;
			}
		}
	}
}