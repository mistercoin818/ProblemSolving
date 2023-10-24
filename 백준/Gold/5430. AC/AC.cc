#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
int T;
string p;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> T;
	for (int t = 0; t < T; ++t) {
		cin >> p;
		int l = p.length();
		int n;
		cin >> n;
		string arr;
		cin >> arr;
		deque<string> v;
		string temp = "";
		for (int i = 1; i < arr.length()-1; ++i) {
			if (arr[i] == ',') {
				v.push_back(temp);
				temp = "";
			}
			else {
				temp += arr[i];
			}
		}
		if (temp.size()) {
			v.push_back(temp);
		}
		bool error_flag = false;
		int reverse_cnt = 0;
		for (int i = 0; i < l; ++i) {
			if (p[i] == 'R') {
				++reverse_cnt;
			}
			if (p[i] == 'D') {
				if (v.empty()) {
					error_flag = true;
					break;
				}
				else {
					if (reverse_cnt % 2) {
						v.pop_back();
					}
					else {
						v.pop_front();
					}
				}
			}
		}
		if (error_flag) {
			cout << "error\n";
		}
		else {
			cout << '[';
			if (reverse_cnt % 2) {
				for (int i = v.size() - 1; i >= 0; --i) {
					if (i) {
						cout << v[i] << ',';
					}
					else{
						cout << v[i];
					}
				}
			}
			else {
				for (int i = 0; i < v.size(); ++i) {
					if (i == v.size() - 1) {
						cout << v[i];
					}
					else {
						cout << v[i] << ',';
					}
				}
			}
			cout << "]\n";
		}
	}
}