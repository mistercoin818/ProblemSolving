#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int R, C, days;
bool visited[1500][1500], oneSwanVisited[1500][1500], anotherSwanVisited[1500][1500], areMet;
char nowRiver[1500][1500], nextRiver[1500][1500];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
vector<pair<int, int>> swans, xToDot;

void dfs(int y, int x){
	visited[y][x] = true;
	for(int i = 0; i < 4; ++i){
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(ny < 0 || nx < 0 || ny >= R || nx >= C) continue;
		if(visited[ny][nx]) continue;
		if(nowRiver[ny][nx] == 'X'){
			nextRiver[ny][nx] = '.';
			xToDot.push_back({ny, nx});
			continue;
		}
		if(nowRiver[ny][nx] == '.') dfs(ny, nx);
	}
	return;
}

void expansionOne(int y, int x){
	oneSwanVisited[y][x] = true;
	for(int i = 0; i < 4; ++i){
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(ny < 0 || nx < 0 || ny >= R || nx >= C) continue;
		if(oneSwanVisited[ny][nx]) continue;
		if(nowRiver[ny][nx] == '.') expansionOne(ny, nx);
	}
	return;
}

void expansionAnother(int y, int x){
	anotherSwanVisited[y][x] = true;
	for(int i = 0; i < 4; ++i){
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(ny < 0 || nx < 0 || ny >= R || nx >= C) continue;
		if(anotherSwanVisited[ny][nx]) continue;
		if(nowRiver[ny][nx] == '.') expansionAnother(ny, nx);
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin >> R >> C;
	for(int r = 0; r < R; ++r){
		string s;
		cin >> s;
		for(int c = 0; c < C; ++c){
			nowRiver[r][c] = s[c];
			nextRiver[r][c] = nowRiver[r][c];
			if(s[c] == '.') xToDot.push_back({r, c});
			else if(s[c] == 'L') {
				swans.push_back({r, c});
				xToDot.push_back({r, c});
			}
		}
	}
	oneSwanVisited[swans[0].first][swans[0].second] = true;
	anotherSwanVisited[swans[1].first][swans[1].second] = true;
	do{
		int l = xToDot.size();
		for(int i = 0; i < l; ++i){
			for(int j = 0; j < 4; ++j){
				int ny = xToDot[i].first + dy[j];
				int nx = xToDot[i].second + dx[j];
				if(ny < 0 || nx < 0 || ny >= R || nx >= C) continue;
				if(oneSwanVisited[ny][nx] && !oneSwanVisited[xToDot[i].first][xToDot[i].second]) expansionOne(xToDot[i].first, xToDot[i].second);
			}
		}
		for(int i = 0; i < l; ++i){
			for(int j = 0; j < 4; ++j){
				int ny = xToDot[i].first + dy[j];
				int nx = xToDot[i].second + dx[j];
				if(ny < 0 || nx < 0 || ny >= R || nx >= C) continue;
				if(anotherSwanVisited[ny][nx] && !anotherSwanVisited[xToDot[i].first][xToDot[i].second]) expansionAnother(xToDot[i].first, xToDot[i].second);
			}
		}
		for(int i = 0; i < l; ++i){
			if(oneSwanVisited[xToDot[i].first][xToDot[i].second] && anotherSwanVisited[xToDot[i].first][xToDot[i].second]){
				areMet = true;
				break;
			}
		}
		if(!areMet){
			vector<pair<int, int>> temp = xToDot;
			xToDot.clear();
			for(int i = 0; i < l; ++i){
				if(!visited[temp[i].first][temp[i].second]){
					dfs(temp[i].first, temp[i].second);
				}
			}
			++days;
			int ll = xToDot.size();
			for(int i = 0; i < ll; ++i){
				nowRiver[xToDot[i].first][xToDot[i].second] = nextRiver[xToDot[i].first][xToDot[i].second];
			}
		}
	}while(!areMet);
	cout << days;
}