#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
const int max_n = 100001;
int N, M, A, B, maxi;
vector<int> arr[max_n], v, temp;
queue<int> q;
bool visited[max_n];

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 0; i < M; ++i) {
		cin >> A >> B;
		arr[B].push_back(A);
	}
	for (int i = 1; i <= M; ++i) {
		q.push(i);
		temp.push_back(i);
		visited[i] = true;
		while (q.size()) {
			int l = arr[q.front()].size();
			for (int j = 0; j < l; ++j) {
				if (!visited[arr[q.front()][j]]) {
					q.push(arr[q.front()][j]);
					temp.push_back(arr[q.front()][j]);
					visited[arr[q.front()][j]] = true;
				}
			}
			q.pop();
		}
		memset(visited, false, sizeof(visited));
		if (temp.size() > maxi) {
			v.clear();
			v.push_back(i);
			maxi = temp.size();
		}
		else if (temp.size() == maxi) {
			v.push_back(i);
		}
		temp.clear();
	}
	for (int a : v) {
		cout << a << ' ';
	}
}