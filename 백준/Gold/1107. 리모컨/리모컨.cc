#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
using namespace std;
string N;
int M, mini, l;
bool canOperate[10];
vector<int> candidates;
void making(string candidate) {
	if (candidate.length() == 6) {
		candidates.push_back(stoi(candidate));
		return;
	}
	vector<string> temp;
	for (int i = 0; i <= 9; ++i) {
		if (canOperate[i]) {
			temp.push_back(candidate + (char)(i + 48));
		}
	}
	for (int i = 0; i < temp.size(); ++i) {
		candidates.push_back(stoi(temp[i]));
		making(temp[i]);
	}
	return;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	memset(canOperate, true, sizeof(canOperate));
	for (int i = 0; i < M; ++i) {
		int brokenNum;
		cin >> brokenNum;
		canOperate[brokenNum] = false;
	}
	l = N.length();
	for (int i = 0; i <= 9; ++i) {
		if (canOperate[i]) {
			candidates.push_back(i);
			making(to_string(i));
		}
	}
	mini = abs(100 - stoi(N));
	for (int a : candidates) {
		mini = min(mini, (int)(to_string(a).length() + abs(stoi(N) - a)));
	}
	cout << mini;
}