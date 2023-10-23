#include <iostream>
#include <vector>

using namespace std;
int N, K, index;
vector<vector<int>> v;
bool visited[200001];

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N >> K;
	visited[N] = true;
	vector<int> vec;
	vec.push_back(N);
	v.push_back(vec);
	bool flag = false;

	while (true) {
		int l = v[index].size();
		++index;
		vector<int> temp;
		for (int i = 0; i < l; ++i) {
			if (v[index - 1][i] * 2 <= 200000 && !visited[v[index-1][i] * 2]) {
				temp.push_back(v[index-1][i] * 2);
				visited[v[index-1][i] * 2] = true;
			}
			if (v[index - 1][i] + 1 <= 200000 && !visited[v[index-1][i] + 1]) {
				temp.push_back(v[index-1][i] + 1);
				visited[v[index-1][i] + 1] = true;
			}
			if (v[index - 1][i] -1 >= 0 && !visited[v[index-1][i] - 1]) {
				temp.push_back(v[index-1][i] - 1);
				visited[v[index-1][i] - 1] = true;
			}
			if ((v[index-1][i] * 2 == K) || (v[index-1][i] + 1 == K) || (v[index-1][i] - 1 == K)) {
				flag = true;
				break;
			}
		}
		v.push_back(temp);
		if (flag) {
			break;
		}
	}
	if (N == K) cout << 0;
	else {
		cout << index;
	}
}