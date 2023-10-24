#include <iostream>

using namespace std;
const int max_n = 604;
int N, M, cnt, x, y;
char campus[max_n][max_n];
bool visited[max_n][max_n];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void dfs(int y, int x){
    visited[y][x] = true;
    if(campus[y][x] == 'P') ++cnt;
    for(int i = 0; i < 4; ++i){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= N || nx < 0 || nx >= M || campus[ny][nx] == 'X') continue;
        if(visited[ny][nx]) continue;
        dfs(ny, nx);
    }
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);
    cin >> N >> M;
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < M; ++j){
            cin >> campus[i][j];
            if(campus[i][j] == 'I'){
                y = i;
                x = j;
            }
        }
    }
    dfs(y, x);
    if(cnt) cout << cnt;
    else cout << "TT";
}