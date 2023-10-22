#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N;
vector<string> v;

bool compare(string a, string b) {
	int lenA = a.length();
	int lenB = b.length();
	if (lenA != lenB) {
		return lenA < lenB;
	}
	return a < b;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; ++i) {
		string letter;
		cin >> letter;
		int l = letter.length();
		int first = -1;
		int last = l;
		bool flag = false;
		for (int j = 0; j < l; ++j) {
			if ('0' <= letter[j] && letter[j] <= '9') {
				if (!flag) {
					flag = true;
					first = j;
					last = j;
				}
				else {
					last = j;
				}
			}
			else {
				if (flag) {
					string temp = letter.substr(first, last - first + 1);
					if (temp[0] == '0') {
						int ll = temp.length();
						int index = -1;
						for (int k = 0; k < ll; ++k) {
							if (temp[k] != '0') {
								index = k;
								break;
							}
						}
						if (index == -1) {
							v.push_back("0");
						}
						else {
							v.push_back(temp.substr(index, ll - index));
						}
					}
					else {
						v.push_back(temp);
					}
				}
				flag = false;
			}
		}
		if (flag) {
			string temp = letter.substr(first, last - first + 1);
			if (temp[0] == '0') {
				int ll = temp.length();
				int index = -1;
				for (int k = 0; k < ll; ++k) {
					if (temp[k] != '0') {
						index = k;
						break;
					}
				}
				if (index == -1) {
					v.push_back("0");
				}
				else {
					v.push_back(temp.substr(index, ll - index));
				}
			}
			else {
				v.push_back(temp);
			}
		}
	}
	sort(v.begin(), v.end(), compare);
	for (auto s : v) {
		cout << s << '\n';
	}
}