#include <bits/stdc++.h>

using namespace std;
int N;
vector<pair<int, int>> vec;

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		int teamNum;
		string time;
		scanf("%d", &teamNum);
		cin >> time;
		int MM, SS;
		if (time[0] == '0') {
			MM = stoi(time.substr(1, 1));
		}
		else {
			MM = stoi(time.substr(0, 2));
		}
		if (time[3] == '0') {
			SS = stoi(time.substr(4, 1));
		}
		else {
			SS = stoi(time.substr(3, 2));
		}
		vec.push_back(make_pair(teamNum, MM * 60 + SS));
	}
	int one = 0;
	int one_time = 0;
	int two = 0;
	int two_time = 0;
	int one_duringTime = 0;
	int two_duringTime = 0;
	int last_time = 0;
	for (int i = 0; i < N; ++i) {
		if (one == 0 && two == 0) {
			if (vec[i].first == 1) {
				++one;
				last_time = vec[i].second;
				one_time = vec[i].second;
			}
			else{
				++two;
				last_time = vec[i].second;
				two_time = vec[i].second;
			}
		}
		else {
			if (one > two) {
				if (vec[i].first == 1) {
					++one;
					continue;
				}
				else {
					++two;
					if (one > two) {
						continue;
					}
					else {
						one_duringTime += vec[i].second - one_time;
					}
				}
			}
			else if (two > one) {
				if (vec[i].first == 1) {
					++one;
					if (two > one) {
						continue;
					}
					else {
						two_duringTime += vec[i].second - two_time;
					}
				}
				else {
					++two;
					continue;
				}
			}
			else {
				if (vec[i].first == 1) {
					++one;
					last_time = vec[i].second;
					one_time = vec[i].second;
				}
				else {
					++two;
					last_time = vec[i].second;
					two_time = vec[i].second;
				}
			}
		}	
	}

	if (one > two) {
		one_duringTime += 48 * 60 - last_time;
	}
	if (one < two) {
		two_duringTime += 48 * 60 - last_time;
	}
	int MM = one_duringTime / 60;
	int SS = one_duringTime % 60;
	printf("%02d:%02d\n", MM, SS);
	
	MM = two_duringTime / 60;
	SS = two_duringTime % 60;
	printf("%02d:%02d", MM, SS);
}