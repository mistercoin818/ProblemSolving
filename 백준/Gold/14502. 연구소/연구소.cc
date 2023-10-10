#include <bits/stdc++.h>

using namespace std;
const int max_n = 10;
int N, M, lab[max_n][max_n], simulator[max_n][max_n], initialState, maximum = 0;
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
vector<pair<int, int>> vec;
vector<pair<int, int>> secondCoos;
vector<pair<int, int>> thirdCoos;

void dfs(int y, int x) {
	simulator[y][x] = 2;
	
	for (int i = 0; i < 4; ++i) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
		if (!simulator[ny][nx]) {
			dfs(ny, nx);
		}
	}

}

void findZeroCoos(int type, int y, int x) {
	for (int i = y; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (!simulator[i][j]) {
				bool condition = (i == y) && (j > x);
				if (condition || i > y) {
					if (type == 2) {
						secondCoos.push_back({ i, j });
					}
					if (type == 3) {
						thirdCoos.push_back({ i, j });
					}
				}
			}
		}
	}
}

int main() {
	scanf("%d %d", &N, &M);
	initialState = N * M;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			scanf("%d", &lab[i][j]);
			simulator[i][j] = lab[i][j];
			if (lab[i][j] == 2) {
				vec.push_back({ i, j });
			}
		}
	}
	int s = vec.size();

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (!simulator[i][j]) {
				simulator[i][j] = 1;
				secondCoos.clear();
				findZeroCoos(2, i, j);
				if (!secondCoos.empty()) {
					int l = secondCoos.size();
					for (int k = 0; k < l; ++k) {
						simulator[secondCoos[k].first][secondCoos[k].second] = 1;
						thirdCoos.clear();
						findZeroCoos(3, secondCoos[k].first, secondCoos[k].second);
						if (!thirdCoos.empty()) {
							int ll = thirdCoos.size();
							for (int p = 0; p < ll; ++p) {
								simulator[thirdCoos[p].first][thirdCoos[p].second] = 1;
								bool flag = false;

								for (int q = 0; q < s; ++q) {
									flag = true;
									dfs(vec[q].first, vec[q].second);
								}
								int temp = 0;
								for (int row = 0; row < N; ++row) {
									for (int col = 0; col < M; ++col) {

										if (simulator[row][col] == 0) {
											++temp;
										}
									}
								}
								
								if (temp > maximum) {
									maximum = temp;
								}
								if (flag) {
									for (int aa = 0; aa < N; ++aa) {
										for (int bb = 0; bb < M; ++bb) {
											simulator[aa][bb] = lab[aa][bb];
										}
									}
									simulator[i][j] = 1;
									simulator[secondCoos[k].first][secondCoos[k].second] = 1;
								}
								simulator[thirdCoos[p].first][thirdCoos[p].second] = 0;
							}
							
						}
						simulator[secondCoos[k].first][secondCoos[k].second] = 0;
					}
				}
				simulator[i][j] = 0;
			}
		}
	}
	printf("%d", maximum);
}