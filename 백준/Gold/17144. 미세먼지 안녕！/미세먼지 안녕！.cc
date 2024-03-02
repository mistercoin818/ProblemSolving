#include<iostream>
#include<cstring>
using namespace std;

int R, C, T, house[50][50], after[50][50], cleaner[2], cleanCnt, sum;
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

void spread(int y, int x) {
	int spreadAmount = house[y][x] / 5, howMany = 0;
	for (int i = 0; i < 4; ++i) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= R || nx >= C) continue;
		if (house[ny][nx] == -1) continue;
		after[ny][nx] += spreadAmount;
		++howMany;
	}
	after[y][x] -= howMany * spreadAmount;
	return;
}

void upClean() {
	int before = 0;
	for (int c = 1; c < C - 1; ++c) {
		int temp = after[cleaner[0]][c];
		after[cleaner[0]][c] = before;
		before = temp;
	}
	for (int r = cleaner[0]; r > 0; --r) {
		int temp = after[r][C - 1];
		after[r][C - 1] = before;
		before = temp;
	}
	for (int c = C - 1; c > 0; --c) {
		int temp = after[0][c];
		after[0][c] = before;
		before = temp;
	}
	for (int r = 0; r < cleaner[0]; ++r) {
		int temp = after[r][0];
		after[r][0] = before;
		before = temp;
	}
	return;
}

void downClean() {
	int before = 0;
	for (int c = 1; c < C - 1; ++c) {
		int temp = after[cleaner[1]][c];
		after[cleaner[1]][c] = before;
		before = temp;
	}
	for (int r = cleaner[1]; r < R - 1; ++r) {
		int temp = after[r][C - 1];
		after[r][C - 1] = before;
		before = temp;
	}
	for (int c = C - 1; c > 0; --c) {
		int temp = after[R - 1][c];
		after[R - 1][c] = before;
		before = temp;
	}
	for (int r = R - 1; r > cleaner[1]; --r) {
		int temp = after[r][0];
		after[r][0] = before;
		before = temp;
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> R >> C >> T;
	for (int r = 0; r < R; ++r) {
		for (int c = 0; c < C; ++c) {
			cin >> house[r][c];
			after[r][c] = house[r][c];
			if (house[r][c] == -1) cleaner[cleanCnt++] = r;
		}
	}
	for (int t = 0; t < T; ++t) {
		for (int r = 0; r < R; ++r) {
			for (int c = 0; c < C; ++c) {
				if (house[r][c] > 0) spread(r, c);
			}
		}
		upClean();
		downClean();
		memcpy(house, after, sizeof(house));
	}
	for (int r = 0; r < R; ++r) {
		for (int c = 0; c < C; ++c) {
			if (house[r][c] > 0) sum += house[r][c];
		}
	}
	cout << sum;
}