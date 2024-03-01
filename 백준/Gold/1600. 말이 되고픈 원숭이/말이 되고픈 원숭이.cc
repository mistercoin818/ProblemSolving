#include<iostream>
#include<queue>
#include<tuple>
using namespace std;

const int INF = 987654321;
int K, W, H, board[200][200], visited[200][200][31], mini = INF;
int horseY[8] = { -1, -2, -2, -1, 1, 2, 2, 1 };
int horseX[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
queue<pair<pair<int, int>, int>> q;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> K >> W >> H;
	for (int h = 0; h < H; ++h) {
		for (int w = 0; w < W; ++w) {
			cin >> board[h][w];
		}
	}
	visited[0][0][0] = 1;
	q.push({ {0, 0}, 0 });
	while (!q.empty()) {
		int y, x;
		tie(y, x) = q.front().first; int horseCnt = q.front().second; q.pop();
		if (horseCnt < K) {
			for (int i = 0; i < 8; ++i) {
				int ny = y + horseY[i];
				int nx = x + horseX[i];
				if (ny < 0 || nx < 0 || ny >= H || nx >= W) continue;
				if (board[ny][nx]) continue;
				if (visited[ny][nx][horseCnt + 1]) continue;
				visited[ny][nx][horseCnt + 1] = visited[y][x][horseCnt] + 1;
				q.push({ {ny, nx}, horseCnt + 1 });
			}
		}
		for (int i = 0; i < 4; ++i) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= H || nx >= W) continue;
			if (board[ny][nx]) continue;
			if (visited[ny][nx][horseCnt]) continue;
			visited[ny][nx][horseCnt] = visited[y][x][horseCnt] + 1;
			q.push({ {ny, nx}, horseCnt });
		}
	}
	for (int k = 0; k <= K; ++k) mini = visited[H - 1][W - 1][k] && mini > visited[H - 1][W - 1][k] ? visited[H - 1][W - 1][k] : mini;
	if (mini == INF) cout << -1;
	else cout << mini - 1;
}