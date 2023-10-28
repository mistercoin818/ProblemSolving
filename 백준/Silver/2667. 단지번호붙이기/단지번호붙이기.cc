#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int N, ma[26][26], cnt;
bool visited[26][26];
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
vector<int> v;
void dfs(int y, int x) {
	visited[y][x] = true;
	++cnt;
	for (int i = 0; i < 4; ++i) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= N || nx < 0 || nx >= N || !ma[ny][nx]) continue;
		if (visited[ny][nx]) continue;
		dfs(ny, nx);
	}
}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	string str;
	for (int i = 0; i < N; ++i) {
		cin >> str;
		int l = str.length();
        for(int j = 0; j<l; j++){
            if(str[j] == '1') ma[i][j] = 1;
            else ma[i][j] = 0;
        }
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (!visited[i][j] && ma[i][j]) {
				dfs(i, j);
				v.push_back(cnt);
				cnt = 0;
			}
		}
	}
	if (v.empty()) cout << 0;
	else {
		sort(v.begin(), v.end());
		cout << v.size() << '\n';
		for (auto it : v) {
			cout << it << '\n';
		}
	}
}