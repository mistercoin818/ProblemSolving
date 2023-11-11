#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstdlib>
using namespace std;
int N, M, city[50][50], result = INT_MAX;
vector<pair<int, int>> house, chicken, alive;
vector<int> temp;
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> city[i][j];
			if (city[i][j] == 1) house.push_back({ i, j });
			else if (city[i][j] == 2) chicken.push_back({ i, j });
		}
	}
	for (int i = 0; i < M; ++i) {
		temp.push_back(1);
	}
	int l = chicken.size();
	for (int i = 0; i < l - M; ++i) {
		temp.push_back(0);
	}
	do {
		for (int i = 0; i < l; ++i) {
			if (temp[i]) alive.push_back(chicken[i]);
		}
		int noOfHouse = house.size();
		int tmp_result = 0;
		for (int i = 0; i < noOfHouse; ++i) {
			int mini = INT_MAX;
			for (int j = 0; j < M; ++j) {
				int tmp = abs(house[i].first - alive[j].first) + abs(house[i].second - alive[j].second);
				if (mini > tmp) mini = tmp;
			}
			tmp_result += mini;
		}
		result = min(result, tmp_result);
		alive.clear();
	} while (prev_permutation(temp.begin(), temp.end()));
	
	cout << result;
}