#include <iostream>
#include <vector>

using namespace std;
int N, M;
vector<int> v;
bool visited[10];


void go(int x) {
	if (v.size() == M) {
		for (int i = 0; i < M; ++i) {
			cout << v[i] << " ";
		}
		cout << '\n';
		return;
	}
	for (int i = x; i <= N; ++i) {
		if (visited[x]) continue;
		visited[x] = 1;
		v.push_back(i);
		go(i +1);
		visited[x] = 0;
		v.pop_back();
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N >> M;
	go(1);
}