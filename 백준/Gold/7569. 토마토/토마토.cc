#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;
const int max_n = 104;
int N, M, H, tomato[max_n][max_n][max_n], visited[max_n][max_n][max_n], mini = 2147483647, x, y, z;
int dz[6] = { 1, -1, 0, 0, 0, 0 };
int dy[6] = { 0, 0, 1, -1, 0, 0 };
int dx[6] = { 0, 0, 0, 0, 1, -1 };
queue<pair<int, int>> qYX;
queue<int> qZ;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> M >> N >> H;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < M; ++k) {
                cin >> tomato[i][j][k];
                if (tomato[i][j][k] == 1) {
                    qYX.push({ j, k });
                    qZ.push(i);
                    visited[i][j][k] = 1;
                }
                else if (tomato[i][j][k] == -1) {
                    visited[i][j][k] = -1;
                }
            }
        }
    }

    int days = 0;
    bool isAllRipen = true;
    while (qZ.size()) {
        tie(y, x) = qYX.front();
        z = qZ.front();
        qYX.pop();
        qZ.pop();
        for (int i = 0; i < 6; ++i) {
            int nz = z + dz[i];
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (nz < 0 || ny < 0 || nx < 0 || nz >= H || ny >= N || nx >= M || tomato[nz][ny][nx] == -1 || tomato[nz][ny][nx] == 1) continue;
            if (visited[nz][ny][nx]) continue;
            if (tomato[nz][ny][nx] == 0) {
                tomato[nz][ny][nx] = 1;
                visited[nz][ny][nx] = visited[z][y][x] + 1;
                qYX.push({ ny, nx });
                qZ.push(nz);
                if (visited[nz][ny][nx] > days) days = visited[nz][ny][nx];
            }
        }
    }

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < M; ++k) {
                if (visited[i][j][k] == 0) {
                    isAllRipen = false;
                }
            }
        }
    }
    if (isAllRipen) {
        if (days == 0) {
            cout << 0;
        }
        else {
            cout << days - 1;
        }
    }
    else cout << -1;
}