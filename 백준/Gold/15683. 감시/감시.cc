#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int N, M, wall, blind = 64;
char office[8][8];
vector<pair<int, int>> CCTV;

void dfs(int CCTVI) {
	if (CCTVI == CCTV.size()) {
		int temp = 0;
		for (int n = 0; n < N; ++n) {
			for (int m = 0; m < M; ++m) {
				if (office[n][m] == '0') ++temp;
			}
		}
		blind = min(blind, temp);
		return;
	}
	char temp[8][8];
	int y = CCTV[CCTVI].first, x = CCTV[CCTVI].second;
	memcpy(temp, office, sizeof(office));
	if (office[y][x] == '1') {
		for (int i = 0; i < 4; ++i) {
			if (i == 0) {
				for (int s = x + 1; s < M; ++s) {
					if (office[y][s] == '6') break;
					if (office[y][s] == '0') office[y][s] = '#';
				}
			}
			else if (i == 1) {
				for (int s = y + 1; s < N; ++s) {
					if (office[s][x] == '6') break;
					if (office[s][x] == '0') office[s][x] = '#';
				}
			}
			else if (i == 2) {
				for (int s = x - 1; s >= 0; --s) {
					if (office[y][s] == '6') break;
					if (office[y][s] == '0') office[y][s] = '#';
				}
			}
			else {
				for (int s = y - 1; s >= 0; --s) {
					if (office[s][x] == '6') break;
					if (office[s][x] == '0') office[s][x] = '#';
				}
			}
			dfs(CCTVI + 1);
			memcpy(office, temp, sizeof(office));
		}
	}
	else if (office[y][x] == '2') {
		for (int i = 0; i < 2; ++i) {
			if (i == 0) {
				for (int s = x + 1; s < M; ++s) {
					if (office[y][s] == '6') break;
					if (office[y][s] == '0') office[y][s] = '#';
				}
				for (int s = x - 1; s >= 0; --s) {
					if (office[y][s] == '6') break;
					if (office[y][s] == '0') office[y][s] = '#';
				}
			}
			else {
				for (int s = y + 1; s < N; ++s) {
					if (office[s][x] == '6') break;
					if (office[s][x] == '0') office[s][x] = '#';
				}
				for (int s = y - 1; s >= 0; --s) {
					if (office[s][x] == '6') break;
					if (office[s][x] == '0') office[s][x] = '#';
				}
			}
			dfs(CCTVI + 1);
			memcpy(office, temp, sizeof(office));
		}
	}
    else if (office[y][x] == '3') {
		for (int i = 0; i < 4; ++i) {
			if (i == 0) {
				for (int s = y - 1; s >= 0; --s) {
					if (office[s][x] == '6') break;
					if (office[s][x] == '0') office[s][x] = '#';
				}
				for (int s = x + 1; s < M; ++s) {
					if (office[y][s] == '6') break;
					if (office[y][s] == '0') office[y][s] = '#';
				}
			}
			else if (i == 1) {
				for (int s = x + 1; s < M; ++s) {
					if (office[y][s] == '6') break;
					if (office[y][s] == '0') office[y][s] = '#';
				}
				for (int s = y + 1; s < N; ++s) {
					if (office[s][x] == '6') break;
					if (office[s][x] == '0') office[s][x] = '#';
				}
			}
			else if (i == 2) {
				for (int s = y + 1; s < N; ++s) {
					if (office[s][x] == '6') break;
					if (office[s][x] == '0') office[s][x] = '#';
				}
				for (int s = x - 1; s >= 0; --s) {
					if (office[y][s] == '6') break;
					if (office[y][s] == '0') office[y][s] = '#';
				}
			}
			else {
				for (int s = x - 1; s >= 0; --s) {
					if (office[y][s] == '6') break;
					if (office[y][s] == '0') office[y][s] = '#';
				}
				for (int s = y - 1; s >= 0; --s) {
					if (office[s][x] == '6') break;
					if (office[s][x] == '0') office[s][x] = '#';
				}
			}
			dfs(CCTVI + 1);
			memcpy(office, temp, sizeof(office));
		}
	}
	else if (office[y][x] == '4') {
		for (int i = 0; i < 4; ++i) {
			if (i == 0) {
				for (int s = x + 1; s < M; ++s) {
					if (office[y][s] == '6') break;
					if (office[y][s] == '0') office[y][s] = '#';
				}
				for (int s = y + 1; s < N; ++s) {
					if (office[s][x] == '6') break;
					if (office[s][x] == '0') office[s][x] = '#';
				}
				for (int s = y - 1; s >= 0; --s) {
					if (office[s][x] == '6') break;
					if (office[s][x] == '0') office[s][x] = '#';
				}
			}
			else if (i == 1) {
				for (int s = x + 1; s < M; ++s) {
					if (office[y][s] == '6') break;
					if (office[y][s] == '0') office[y][s] = '#';
				}
				for (int s = y + 1; s < N; ++s) {
					if (office[s][x] == '6') break;
					if (office[s][x] == '0') office[s][x] = '#';
				}
				for (int s = x - 1; s >= 0; --s) {
					if (office[y][s] == '6') break;
					if (office[y][s] == '0') office[y][s] = '#';
				}
			}
			else if (i == 2) {
				for (int s = y - 1; s >= 0; --s) {
					if (office[s][x] == '6') break;
					if (office[s][x] == '0') office[s][x] = '#';
				}
				for (int s = x - 1; s >= 0; --s) {
					if (office[y][s] == '6') break;
					if (office[y][s] == '0') office[y][s] = '#';
				}
				for (int s = y + 1; s < N; ++s) {
					if (office[s][x] == '6') break;
					if (office[s][x] == '0') office[s][x] = '#';
				}
			}
			else {
				for (int s = y - 1; s >= 0; --s) {
					if (office[s][x] == '6') break;
					if (office[s][x] == '0') office[s][x] = '#';
				}
				for (int s = x + 1; s < M; ++s) {
					if (office[y][s] == '6') break;
					if (office[y][s] == '0') office[y][s] = '#';
				}
				for (int s = x - 1; s >= 0; --s) {
					if (office[y][s] == '6') break;
					if (office[y][s] == '0') office[y][s] = '#';
				}
			}
			dfs(CCTVI + 1);
			memcpy(office, temp, sizeof(office));
		}
	}
	else {
		for (int i = 0; i < 4; ++i) {
			for (int s = x + 1; s < M; ++s) {
				if (office[y][s] == '6') break;
				if (office[y][s] == '0') office[y][s] = '#';
			}
			for (int s = y + 1; s < N; ++s) {
				if (office[s][x] == '6') break;
				if (office[s][x] == '0') office[s][x] = '#';
			}
			for (int s = x - 1; s >= 0; --s) {
				if (office[y][s] == '6') break;
				if (office[y][s] == '0') office[y][s] = '#';
			}
			for (int s = y - 1; s >= 0; --s) {
				if (office[s][x] == '6') break;
				if (office[s][x] == '0') office[s][x] = '#';
			}
			dfs(CCTVI + 1);
			memcpy(office, temp, sizeof(office));
		}
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int n = 0; n < N; ++n) {
		for (int m = 0; m < M; ++m) {
			cin >> office[n][m];
			if ('1' <= office[n][m] && office[n][m] <= '5') CCTV.push_back({ n, m });
		}
	}
	dfs(0);
	cout << blind;
}