#include <iostream>
#include <map>
#include <queue>
using namespace std;
int N, M, visited[101];
map<int, int> snakesAndLadders;
queue<int> q;
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin >> N >> M;
	for(int i = 0; i < N; ++i){
		int x, y;
		cin >> x >> y;
		snakesAndLadders[x] = y;
	}
	for(int i = 0; i < M; ++i){
		int u, v;
		cin >> u >> v;
		snakesAndLadders[u] = v;
	}
	q.push(1);
	visited[1] = 1;
	while(!q.empty()){
		int coo = q.front(); q.pop();
		if(coo == 100) break;
		for(int i = 1; i <= 6; ++i){
			int next_coo = coo + i;
			if(next_coo > 100) continue;
			map<int, int>::iterator iter = snakesAndLadders.find(next_coo);
			if(iter != snakesAndLadders.end()) next_coo = iter->second;
			if(!visited[next_coo]){
				visited[next_coo] = visited[coo] + 1;
				q.push(next_coo);
			}
			
		}
	}
	cout << visited[100] - 1;
}